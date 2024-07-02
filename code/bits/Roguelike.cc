#include "Roguelike.h"

#include "config.h"

namespace rl {

  Roguelike::Roguelike()
  : gf::SceneSystem("Roguelike", { 1600, 900 }, RL2024_DATADIR)
  {
    auto bundle = world_bundle();
    bundle.load_from(resource_manager());

    push_scene(&world_scene);
  }

  gf::ResourceBundle Roguelike::world_bundle()
  {
    return gf::ResourceBundle([this](gf::ResourceBundle* bundle, gf::ResourceManager* resource_manager, gf::ResourceAction action) {
      bundle->handle<gf::ConsoleFont>("dejavu10x10_gs_tc.png", { gf::LibtcodFormat, { 0, 0 }, render_manager() }, resource_manager, action);
    });
  }

}
