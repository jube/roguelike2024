#include "Map.h"

#include <cassert>

namespace rl {

  namespace {

    struct TileData {
      char16_t character = ' ';
      gf::Color light;
      gf::Color dark;
    };

    constexpr TileData Tileset[] = {
      { ' ', gf::Black, 0x000064 }, // Wall
      { ' ', gf::Black, 0x323296 }, // Floor
    };

  }


  gf::Color tile_to_dark_color(Tile tile)
  {
    std::size_t index = static_cast<uint16_t>(tile);
    assert(index < std::size(Tileset));
    return Tileset[index].dark; // NOLINT
  }

  gf::Color tile_to_light_color(Tile tile)
  {
    std::size_t index = static_cast<uint16_t>(tile);
    assert(index < std::size(Tileset));
    return Tileset[index].light; // NOLINT
  }





  gf::GridMap generate_dungeon(gf::Vec2I size)
  {
    gf::GridMap map = gf::GridMap::make_orthogonal(size);
    map.reset(gf::None);

    const gf::RectI room1 = gf::RectI::from_position_size({ 20, 15 }, { 10, 15 });
    const gf::RectI room2 = gf::RectI::from_position_size({ 35, 15 }, { 10, 15 });

    for (const gf::RectI room : { room1, room2 }) {
      for (auto position : gf::rectangle_range(room.shrink_by(1))) {
        map.set_empty(position);
        map.set_tag(position, Tile::Floor);
      }
    }

    return map;
  }

}
