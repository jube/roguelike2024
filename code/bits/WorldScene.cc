#include "WorldScene.h"

#include "Map.h"
#include "Roguelike.h"
#include "Tile.h"

namespace rl {
  constexpr gf::Vec2 ScreenSize = { 80, 50 };
  constexpr gf::Vec2 MapSize = { 80, 50 };

  constexpr int RoomMaxSize = 10;
  constexpr int RoomMinSize = 6;
  constexpr int MaxRooms = 30;

  WorldScene::WorldScene(Roguelike* game)
  : m_game(game)
  , m_action_group(m_data.action_group)
  , m_root_console(ScreenSize)
  , m_console_font(game->resource_manager()->get<gf::ConsoleFont>("dejavu10x10_gs_tc.png"))
  , m_console_entity(m_console_font, m_root_console, game->render_manager())
  {
    auto world_size = ScreenSize * m_console_font->character_size();
    set_world_size(world_size);
    set_world_center(world_size / 2);

    m_state.hero = { ScreenSize / 2, '@', gf::White };
    m_state.objects.emplace_back(m_state.hero.position() - gf::dirx(5), '@', gf::Yellow);

    m_state.map = generate_dungeon(MapSize, MaxRooms, RoomMinSize, RoomMaxSize, &m_state.hero, game->random());
    update_field_of_view();

    add_world_entity(&m_console_entity);
  }

  void WorldScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void WorldScene::do_handle_actions()
  {
    using namespace gf::literals;

    if (m_action_group.active("up"_id)) {
      m_state.hero_direction = gf::Direction::Up;
    } else if (m_action_group.active("left"_id)) {
      m_state.hero_direction = gf::Direction::Left;
    } else if (m_action_group.active("down"_id)) {
      m_state.hero_direction = gf::Direction::Down;
    } else if (m_action_group.active("right"_id)) {
      m_state.hero_direction = gf::Direction::Right;
    } else {
      m_state.hero_direction = gf::Direction::Center;
    }

    m_action_group.reset();
  }

  void WorldScene::do_update([[maybe_unused]] gf::Time time)
  {
    m_state.update();
    update_field_of_view();

    m_root_console.clear();

    for (auto position : m_state.map.position_range()) {
      const Tile tile = m_state.map.tag_as<Tile>(position);
      gf::ConsoleCell cell = { gf::White, gf::Black, ' ' };

      if (m_state.map.visible(position)) {
        cell = tile_to_light(tile);
      } else if (m_state.map.explored(position)) {
        cell = tile_to_dark(tile);
      }

      m_root_console.cells(position) = cell;
    }

    {
      gf::ConsoleStyle style;
      style.color.foreground = m_state.hero.color();
      style.effect = gf::ConsoleEffect::none();
      m_root_console.put_character(m_state.hero.position(), m_state.hero.character(), style);
    }

    for (auto& object : m_state.objects) {
      if (!m_state.map.visible(object.position())) {
        continue;
      }

      gf::ConsoleStyle style;
      style.color.foreground = object.color();
      style.effect = gf::ConsoleEffect::none();
      m_root_console.put_character(object.position(), object.character(), style);
    }

    m_console_entity.console().update(m_root_console, m_game->render_manager());
  }

  void WorldScene::update_field_of_view()
  {
    m_state.map.clear_visible();
    m_state.map.compute_field_of_vision(m_state.hero.position(), 8, gf::Visibility::ShadowCast);
  }


}
