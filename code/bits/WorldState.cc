#include "WorldState.h"

#include <algorithm>
#include <iostream>

#include "Tile.h"

namespace rl {

  void WorldState::update()
  {
    if (hero_direction == gf::Direction::Center) {
      return;
    }

    auto displacement = gf::displacement(hero_direction);
    auto target = map.hero.position + displacement;

    if (!map.grid.valid(target)) {
      return;
    }

    if (!map.grid.walkable(target)) {
      return;
    }

    auto maybe_object_index = blocking_object_at(target);

    if (!maybe_object_index) {
      // movement
      map.hero.position = target;
    } else {
      // melee
      auto object_index = *maybe_object_index;
      std::cout << "You kicked " << map.objects[object_index].name << ", much to its annoyance!\n";
    }

    // handle ennemy turns

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

    {
      gf::ConsoleStyle style;
      style.color.foreground = map.hero.color;
      style.effect = gf::ConsoleEffect::none();
      buffer.put_character(map.hero.position, map.hero.character, style);
    }

    for (auto& object : map.objects) {
      if (!grid.visible(object.position)) {
        continue;
      }

      gf::ConsoleStyle style;
      style.color.foreground = object.color;
      style.effect = gf::ConsoleEffect::none();
      buffer.put_character(object.position, object.character, style);
    }

  }


  std::optional<std::size_t> WorldState::blocking_object_at(gf::Vec2I position) const
  {
    auto iterator = std::find_if(map.objects.begin(), map.objects.end(), [position](const Object& object) {
      return object.position == position;
    });

    if (iterator == map.objects.end()) {
      return std::nullopt;
    }

    return std::distance(map.objects.begin(), iterator);
  }

}
