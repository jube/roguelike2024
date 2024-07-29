#ifndef RL_ACTOR_H
#define RL_ACTOR_H

#include <optional>

#include "AI.h"
#include "Fighter.h"
#include "Entity.h"

namespace rl {

  struct Actor {
    Entity entity;
    Fighter fighter;
    std::optional<AI> ai;

    bool alive() const
    {
      return ai.has_value();
    }


    static Actor hero(gf::Vec2I position);
    static Actor orc(gf::Vec2I position);
    static Actor troll(gf::Vec2I position);

  };

}

#endif // RL_ACTOR_H
