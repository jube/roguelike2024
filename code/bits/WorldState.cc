#include "WorldState.h"

#include <algorithm>
#include <iostream>

#include "Actions.h"
#include "Tile.h"

namespace rl {

  void WorldState::update()
  {
    if (intent == Intent::None) {
      return;
    }

    if (intent == Intent::Move) {
      if (hero_direction == gf::Direction::Center) {
        return;
      }

      auto displacement = gf::displacement(hero_direction);
      auto target = map.hero().entity.position + displacement;

      if (!bump(map, map.hero(), target)) {
        return;
      }
    } else if (intent == Intent::Wait) {
      // nothing
    }

    // handle ennemy turns

    for (auto& actor : map.actors) {
      actor.ai.perform(actor, map);
    }

  }

  void WorldState::render_to(gf::ConsoleBuffer& buffer)
  {
    auto& grid = map.grid;

    for (auto position : grid.position_range()) {
      const Tile tile = grid.tag_as<Tile>(position);
      gf::ConsoleCell cell = { gf::White, gf::Black, ' ' };

      if (grid.visible(position)) {
        cell = tile_to_light(tile);
      } else if (grid.explored(position)) {
        cell = tile_to_dark(tile);
      }

      buffer.cells(position) = cell;
    }

    for (auto& actor : map.actors) {
      if (!grid.visible(actor.entity.position)) {
        continue;
      }

      gf::ConsoleStyle style;
      style.color.foreground = actor.entity.color;
      style.effect = gf::ConsoleEffect::none();
      buffer.put_character(actor.entity.position, actor.entity.character, style);
    }

  }

}
