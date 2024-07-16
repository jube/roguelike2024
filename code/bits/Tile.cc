#include "Tile.h"

namespace rl {

  namespace {

    struct TileData {
      gf::ConsoleCell light;
      gf::ConsoleCell dark;
    };

    constexpr TileData Tileset[] = {
      { { gf::Black, 0x826E32, ' ' }, { gf::Black, 0x000064, ' ' } }, // Wall
      { { gf::Black, 0xC8B432, ' ' }, { gf::Black, 0x323296, ' ' } }, // Floor
    };

  }

  gf::ConsoleCell tile_to_dark(Tile tile)
  {
    std::size_t index = static_cast<uint16_t>(tile);
    assert(index < std::size(Tileset));
    return Tileset[index].dark; // NOLINT
  }

  gf::ConsoleCell tile_to_light(Tile tile)
  {
    std::size_t index = static_cast<uint16_t>(tile);
    assert(index < std::size(Tileset));
    return Tileset[index].light; // NOLINT
  }

}
