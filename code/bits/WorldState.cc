#include "WorldState.h"

namespace rl {

  void WorldState::update()
  {
    if (hero_direction != gf::Direction::Center) {
      auto displacement = gf::displacement(hero_direction);
      auto target = hero.position() + displacement;

      if (map.valid(target) && map.walkable(target)) {
        hero.move(displacement);
      }
    }
  }

}
