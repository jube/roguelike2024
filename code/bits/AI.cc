#include "AI.h"

#include "Actor.h"
#include "Map.h"

namespace rl {

  void HostileEnnemyAI::perform(Actor& self, Map& map)
  {
    const gf::Vec2I target = map.hero.entity.position;
  }

}
