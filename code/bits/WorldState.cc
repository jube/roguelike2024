#include "WorldState.h"

namespace rl {

  void WorldState::update()
  {
    auto displacement = gf::displacement(hero_direction);
    auto target = hero.position() + displacement;

    if (map.tiles.valid(target) && map.properties.walkable(hero.position() + displacement)) {
      hero.move(displacement);
    }
  }

}
