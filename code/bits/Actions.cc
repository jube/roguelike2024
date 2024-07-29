#include "Actions.h"

#include <cassert>

#include <iostream>

#include "Actor.h"
#include "Map.h"

namespace rl {

  bool bump(Map& map, Actor& actor, gf::Vec2I target)
  {
    if (auto maybe_actor = map.target_actor_at(target); maybe_actor) {
      return melee(map, actor, target);
    }

    return movement(map, actor, target);
  }

  bool movement(Map& map, Actor& actor, gf::Vec2I target)
  {
    if (!map.grid.valid(target)) {
      return false;
    }

    if (!map.grid.walkable(target)) {
      return false;
    }

    if (map.blocking_entity_at(target)) {
      return false;
    }

    actor.entity.position = target;
    return true;
  }

  bool melee(Map& map, Actor& actor, gf::Vec2I target)
  {
    auto maybe_actor = map.target_actor_at(target);
    assert(maybe_actor);

    auto actor_index = *maybe_actor;
    std::cout << "You kicked " << map.actors[actor_index].entity.name << ", much to its annoyance!\n";
    return true;
  }

}
