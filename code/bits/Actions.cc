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

    auto& other = map.actors[*maybe_actor];

    int damage = actor.fighter.power - other.fighter.defense;

    std::string description = actor.entity.name + " attacks " + other.entity.name;

    if (damage > 0) {
      std::cout << description << " for " << damage << " hit points.\n";
      other.fighter.health -= damage;
    } else {
      std::cout << description << " but does no damage.\n";
    }

    return true;
  }

}
