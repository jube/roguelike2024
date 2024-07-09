#ifndef RL_WORLD_STATE_H
#define RL_WORLD_STATE_H

#include <vector>

#include <gf2/core/Direction.h>
#include <gf2/core/Vec2.h>

#include "Object.h"

namespace rl {

  struct WorldState {
    Object hero;
    gf::Direction hero_direction = gf::Direction::Center;

    std::vector<Object> objects;

    void update();
  };

}

#endif // RL_WORLD_STATE_H
