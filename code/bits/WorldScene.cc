#include "WorldScene.h"

#include "Map.h"
#include "Roguelike.h"

namespace rl {
  constexpr gf::Vec2 ScreenSize = { 80, 50 };
  constexpr gf::Vec2 MapSize = { 80, 50 };

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

    m_state.map = generate_dungeon(MapSize);

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

    m_root_console.clear();

    for (auto position : m_state.map.position_range()) {
      m_root_console.set_background(position, tile_to_dark_color(m_state.map.tag_as<Tile>(position)));
    }

    {
      gf::ConsoleStyle style;
      style.color.foreground = m_state.hero.color();
      style.effect = gf::ConsoleEffect::none();
      m_root_console.put_character(m_state.hero.position(), m_state.hero.character(), style);
    }

    for (auto& object : m_state.objects) {
      gf::ConsoleStyle style;
      style.color.foreground = object.color();
      style.effect = gf::ConsoleEffect::none();
      m_root_console.put_character(object.position(), object.character(), style);
    }

    m_console_entity.console().update(m_root_console, m_game->render_manager());
  }

}
