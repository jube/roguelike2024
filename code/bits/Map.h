#ifndef RL_MAP_H
#define RL_MAP_H

#include <gf2/core/Array2D.h>
#include <gf2/core/Color.h>
#include <gf2/core/GridMap.h>

namespace rl {

  struct Tile {
    char16_t character = ' ';
    gf::Color light;
    gf::Color dark;
  };

  constexpr Tile FloorTile = { ' ', gf::Black, 0x323296 };
  constexpr Tile WallTile = { ' ', gf::Black, 0x000064 };

  struct Map {
    Map() = default;
    Map(gf::Vec2I size);

    gf::GridMap properties;
    gf::Array2D<Tile> tiles;
  };

}

#endif // RL_MAP_H
