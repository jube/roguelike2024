#include "WorldState.h"

namespace rl {

  void WorldState::update()
  {
    hero_position += gf::displacement(hero_direction);
  }

}
