#include "WorldState.h"

namespace rl {

  void WorldState::update()
  {
    hero.move(gf::displacement(hero_direction));
  }

}
