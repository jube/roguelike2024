#include "Roguelike.h"

#include "WorldScene.h"
#include "config.h"

namespace rl {

  Roguelike::Roguelike()
  : gf::SceneSystem("Roguelike", { 1600, 900 }, RL2024_DATADIR)
  {
    auto bundle = world_bundle();
    bundle.load_from(resource_manager());

    m_world_scene = std::make_unique<WorldScene>(this);
    push_scene(m_world_scene.get());
  }

  gf::ResourceBundle Roguelike::world_bundle()
  {
    return gf::ResourceBundle([this](gf::ResourceBundle* bundle, gf::ResourceManager* resource_manager, gf::ResourceAction action) {
      bundle->handle<gf::ConsoleFont>("dejavu10x10_gs_tc.png", { gf::LibtcodFormat, { 0, 0 }, render_manager() }, resource_manager, action);
    });
  }

}
