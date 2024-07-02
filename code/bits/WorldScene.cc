#include "WorldScene.h"

#include "Roguelike.h"

namespace rl {
  constexpr gf::Vec2 ScreenSize = { 80, 50 };

  WorldScene::WorldScene(Roguelike* game)
  : m_game(game)
  , m_root_console(ScreenSize)
  , m_console_font(game->resource_manager()->get<gf::ConsoleFont>("dejavu10x10_gs_tc.png"))
  , m_console_entity(m_console_font, m_root_console, game->render_manager())
  {
    auto world_size = ScreenSize * 10;
    set_world_size(world_size);
    set_world_center(world_size / 2);

    m_state.hero_position = ScreenSize / 2;

    add_world_entity(&m_console_entity);
  }

  void WorldScene::do_update([[maybe_unused]] gf::Time time)
  {

    m_root_console.put_character(m_state.hero_position, '@');

    m_console_entity.console().update(m_root_console, m_game->render_manager());
  }

}
