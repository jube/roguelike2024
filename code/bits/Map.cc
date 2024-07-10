#include "Map.h"

#include <cassert>

#include <algorithm>

#include <gf2/core/Geometry.h>

#include "Object.h"

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

  gf::GridMap generate_dungeon(gf::Vec2I size, int max_rooms, int room_min_size, int room_max_size, Object* hero,  gf::Random* random)
  {
    gf::GridMap map = gf::GridMap::make_orthogonal(size);
    map.reset(gf::None);

    std::vector<gf::RectI> rooms;

    for (int i = 0; i < max_rooms; ++i) {
      gf::Vec2I room_size = { 0, 0 };
      room_size.w = random->compute_uniform_integer(room_min_size, room_max_size);
      room_size.h = random->compute_uniform_integer(room_min_size, room_max_size);

      gf::Vec2I room_position = { 0, 0 };
      room_position.x = random->compute_uniform_integer(0, size.w - room_size.w);
      room_position.y = random->compute_uniform_integer(0, size.h - room_size.h);

      const gf::RectI room = gf::RectI::from_position_size(room_position, room_size);

      if (std::any_of(rooms.begin(), rooms.end(), [room](const gf::RectI& other_room) { return room.intersects(other_room); })) {
        continue;
      }

      for (auto position : gf::rectangle_range(room.shrink_by(1))) {
        map.set_empty(position);
        map.set_tag(position, Tile::Floor);
      }

      if (rooms.empty()) {
        hero->set_position(room.center());
      } else {
        dig_tunnel_between(map, rooms.back().center(), room.center(), random);
      }

      rooms.push_back(room);
    }

    return map;
  }

}
