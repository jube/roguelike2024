#ifndef RL_AI_H
#define RL_AI_H

#include <vector>
#include <variant>


#include <gf2/core/Vec2.h>

namespace rl {
  struct Actor;
  struct Map;

  struct HostileEnnemyAI {
    std::vector<gf::Vec2I> path;

    void perform(Actor& self, Map& map);

  };


  struct AI {

  };


}

#endif // RL_AI_H
