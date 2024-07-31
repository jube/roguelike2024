#ifndef RL_MAP_H
#define RL_MAP_H

#include <gf2/core/GridMap.h>
#include <gf2/core/Random.h>

#include "Actor.h"

namespace rl {
  struct Map {
    std::vector<Actor> actors;
    gf::GridMap grid;

    Actor& hero() { return actors.front(); }

    std::optional<std::size_t> target_actor_at(gf::Vec2I target);
    bool blocking_entity_at(gf::Vec2I target);

    std::vector<gf::Vec2I> compute_path(gf::Vec2I origin, gf::Vec2I target);
  };

  Map generate_dungeon(gf::Vec2I size, int max_rooms, int room_min_size, int room_max_size, int max_monsters_per_room, gf::Random* random);

}

#endif // RL_MAP_H
