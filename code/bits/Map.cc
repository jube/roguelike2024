#include "Map.h"

#include <cassert>

#include <gf2/core/Geometry.h>

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


  namespace {
    void dig_straight_tunnel_between(gf::GridMap& map, gf::Vec2I start, gf::Vec2I end)
    {
      gf::BresenhamAlgorithm bresenham(start, end);

      while (auto maybe_current = bresenham.step()) {
        auto current = *maybe_current;
        map.set_empty(current);
        map.set_tag(current, Tile::Floor);
      }
    }

    void dig_tunnel_between(gf::GridMap& map, gf::Vec2I start, gf::Vec2I end, gf::Random* random)
    {
      gf::Vec2I corner = { 0, 0 };

      if (random->compute_bernoulli(0.5)) {
        // Move horizontally, then vertically.
        corner.x = end.x;
        corner.y = start.y;
      } else {
        // Move vertically, then horizontally.
        corner.x = start.x;
        corner.y = end.y;
      }

      dig_straight_tunnel_between(map, start, corner);
      dig_straight_tunnel_between(map, corner, end);
    }


  }

  gf::GridMap generate_dungeon(gf::Vec2I size, gf::Random* random)
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

    dig_tunnel_between(map, room1.center(), room2.center(), random);

    return map;
  }

}
