#include "Actor.h"

namespace rl {

  Actor Actor::hero(gf::Vec2I position)
  {
    Actor actor;
    actor.entity = { position, '@', gf::White, "Hero", true };
    return actor;
  }

  Actor Actor::orc(gf::Vec2I position)
  {
    Actor actor;
    actor.entity = { position, 'o', 0x3F7F3F, "Orc", true };
    return actor;
  }

  Actor Actor::troll(gf::Vec2I position)
  {
    Actor actor;
    actor.entity = { position, 'T', 0x007F00, "Troll", true };
    return actor;
  }

}
