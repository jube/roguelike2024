#include "WorldScene.h"

#include "Map.h"
#include "Roguelike.h"
#include "gf2/core/ActionSettings.h"

namespace rl {
  constexpr gf::Vec2 ScreenSize = { 80, 50 };
  constexpr gf::Vec2 MapSize = { 80, 50 };

  constexpr int RoomMaxSize = 10;
  constexpr int RoomMinSize = 6;
  constexpr int MaxRooms = 30;
  constexpr int MaxMonstersPerRoom = 2;


  gf::ActionGroupSettings action_group_settings()
  {
    using namespace gf::literals;

    gf::ActionGroupSettings action_group;
    action_group.actions.emplace("up"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Up).add_scancode_control(gf::Scancode::W));
    action_group.actions.emplace("left"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Left).add_scancode_control(gf::Scancode::A));
    action_group.actions.emplace("down"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Down).add_scancode_control(gf::Scancode::S));
    action_group.actions.emplace("right"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Right).add_scancode_control(gf::Scancode::D));

    action_group.actions.emplace("wait"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Escape));

    return action_group;
  }

  WorldScene::WorldScene(Roguelike* game)
  : m_game(game)
  , m_action_group(action_group_settings())
  , m_root_console(ScreenSize)
  , m_console_font(game->resource_manager()->get<gf::ConsoleFont>("dejavu10x10_gs_tc.png"))
  , m_console_entity(m_console_font, m_root_console, game->render_manager())
  {
    auto world_size = ScreenSize * m_console_font->character_size();
    set_world_size(world_size);
    set_world_center(world_size / 2);

    m_state.map = generate_dungeon(MapSize, MaxRooms, RoomMinSize, RoomMaxSize, MaxMonstersPerRoom, game->random());
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

    m_state.intent = Intent::None;

    if (m_action_group.active("up"_id)) {
      m_state.intent = Intent::Move;
      m_state.hero_direction = gf::Direction::Up;
    } else if (m_action_group.active("left"_id)) {
      m_state.intent = Intent::Move;
      m_state.hero_direction = gf::Direction::Left;
    } else if (m_action_group.active("down"_id)) {
      m_state.intent = Intent::Move;
      m_state.hero_direction = gf::Direction::Down;
    } else if (m_action_group.active("right"_id)) {
      m_state.intent = Intent::Move;
      m_state.hero_direction = gf::Direction::Right;
    } else {
      m_state.hero_direction = gf::Direction::Center;
    }

    if (m_action_group.active("wait"_id)) {
      m_state.intent = Intent::Wait;
    }

    m_action_group.reset();
  }

  void WorldScene::do_update([[maybe_unused]] gf::Time time)
  {
    m_state.update();
    update_field_of_view();

    m_root_console.clear();
    m_state.render_to(m_root_console);
    m_console_entity.console().update(m_root_console, m_game->render_manager());
  }

  void WorldScene::update_field_of_view()
  {
    m_state.map.grid.clear_visible();
    m_state.map.grid.compute_field_of_vision(m_state.map.hero().entity.position, 8, gf::Visibility::ShadowCast);
  }


}
