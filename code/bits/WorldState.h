#ifndef RL_WORLD_STATE_H
#define RL_WORLD_STATE_H

#include <optional>

#include <gf2/core/ConsoleBuffer.h>
#include <gf2/core/Direction.h>

#include "Map.h"

namespace rl {

  struct WorldState {
    gf::Direction hero_direction = gf::Direction::Center;

    Map map;

    void update();
    void render_to(gf::ConsoleBuffer& buffer);

    std::optional<std::size_t> blocking_object_at(gf::Vec2I position) const;

  };

}

#endif // RL_WORLD_STATE_H
