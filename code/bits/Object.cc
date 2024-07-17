#include "Object.h"

namespace rl {

  Object Object::hero(gf::Vec2I position)
  {
    return { position, '@', gf::White, "Hero", true };
  }

  Object Object::orc(gf::Vec2I position)
  {
    return { position, 'o', 0x3F7F3F, "Orc", true };
  }

  Object Object::troll(gf::Vec2I position)
  {
    return { position, 'T', 0x007F00, "Troll", true };
  }

}
