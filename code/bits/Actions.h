#ifndef RL_ACTIONS_H
#define RL_ACTIONS_H

#include <gf2/core/Vec2.h>

namespace rl {
  struct Map;
  struct Actor;

  bool bump(Map& map, Actor& actor, gf::Vec2I target);
  bool movement(Map& map, Actor& actor, gf::Vec2I target);
  bool melee(Map& map, Actor& actor, gf::Vec2I target);


}

#endif // RL_ACTIONS_H
