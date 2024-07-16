#ifndef RL_TILE_H
#define RL_TILE_H

#include <cstdint>

#include <gf2/core/ConsoleBuffer.h>

namespace rl {

  enum Tile : uint16_t {
    Wall,
    Floor,
  };

  gf::ConsoleCell tile_to_dark(Tile tile);
  gf::ConsoleCell tile_to_light(Tile tile);

}

#endif // RL_TILE_H
