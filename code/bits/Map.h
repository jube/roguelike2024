#ifndef RL_MAP_H
#define RL_MAP_H

#include <gf2/core/GridMap.h>
#include <gf2/core/Random.h>

#include "Object.h"

namespace rl {
  struct Map {
    Object hero;
    std::vector<Object> objects;
    gf::GridMap grid;
  };

  Map generate_dungeon(gf::Vec2I size, int max_rooms, int room_min_size, int room_max_size, int max_monsters_per_room, gf::Random* random);

}

#endif // RL_MAP_H
