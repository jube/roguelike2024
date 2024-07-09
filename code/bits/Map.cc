#include "Map.h"

namespace rl {

  Map::Map(gf::Vec2I size)
  : properties(gf::GridMap::make_orthogonal(size))
  , tiles(size, FloorTile)
  {
    properties.reset(gf::CellProperty::Walkable | gf::CellProperty::Visible);

    for (int i = 30; i <= 33; ++i) {
      properties.set_properties({ i, 22 }, gf::None);
      tiles({ i, 22 }) = WallTile;
    }
  }

}
