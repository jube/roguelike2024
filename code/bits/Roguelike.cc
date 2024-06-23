#include "Roguelike.h"

#include "config.h"

namespace rl {

  Roguelike::Roguelike()
  : gf::SceneSystem("Roguelike", { 1600, 900 }, RL2024_DATADIR)
  {
  }

}
