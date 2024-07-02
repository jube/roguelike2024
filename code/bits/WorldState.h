#ifndef RL_WORLD_STATE_H
#define RL_WORLD_STATE_H

#include <gf2/core/Direction.h>
#include <gf2/core/Vec2.h>

namespace rl {

  struct WorldState {
    gf::Vec2I hero_position = { 0, 0 };
    gf::Direction hero_direction = gf::Direction::Center;


    void update();
  };

}

#endif // RL_WORLD_STATE_H
