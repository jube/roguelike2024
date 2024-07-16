#ifndef RL_MAP_H
#define RL_MAP_H

#include <gf2/core/GridMap.h>
#include <gf2/core/Random.h>

namespace rl {
  class Object;

  gf::GridMap generate_dungeon(gf::Vec2I size, int max_rooms, int room_min_size, int room_max_size, Object* hero, gf::Random* random);

}

#endif // RL_MAP_H
