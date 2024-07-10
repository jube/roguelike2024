#ifndef RL_MAP_H
#define RL_MAP_H

#include <cstdint>

#include <gf2/core/Color.h>
#include <gf2/core/GridMap.h>
#include <gf2/core/Random.h>

namespace rl {

  enum Tile : uint16_t {
    Wall,
    Floor,
  };

  gf::Color tile_to_dark_color(Tile tile);
  gf::Color tile_to_light_color(Tile tile);

  gf::GridMap generate_dungeon(gf::Vec2I size, gf::Random* random);

}

#endif // RL_MAP_H
