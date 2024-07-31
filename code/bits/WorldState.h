#ifndef RL_WORLD_STATE_H
#define RL_WORLD_STATE_H

#include <optional>

#include <gf2/core/ConsoleBuffer.h>
#include <gf2/core/Direction.h>

#include "Map.h"

namespace rl {

  enum class Intent {
    None,
    Wait,
    Move,
  };

  struct WorldState {
    Intent intent = Intent::None;
    gf::Direction hero_direction = gf::Direction::Center;

    Map map;

    void update();
    void render_to(gf::ConsoleBuffer& buffer);

  };

}

#endif // RL_WORLD_STATE_H
