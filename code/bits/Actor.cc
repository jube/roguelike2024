#include "Actor.h"

namespace rl {

  void Actor::take_damage(int damage)
  {
    fighter.health -= damage;
    fighter.health = std::max(0, std::min(fighter.health, fighter.max_health));

    // TODO

  }

  void Actor::die()
  {
  }

  Actor Actor::hero(gf::Vec2I position)
  {
    Actor actor;
    actor.entity = { position, '@', gf::White, "Hero", true };
    actor.fighter = Fighter(30, 2, 5);
    return actor;
  }

  Actor Actor::orc(gf::Vec2I position)
  {
    Actor actor;
    actor.entity = { position, 'o', 0x3F7F3F, "Orc", true };
    actor.fighter = Fighter(10, 0, 3);
    actor.ai = AI::hostile();
    return actor;
  }

  Actor Actor::troll(gf::Vec2I position)
  {
    Actor actor;
    actor.entity = { position, 'T', 0x007F00, "Troll", true };
    actor.fighter = Fighter(16, 1, 4);
    actor.ai = AI::hostile();
    return actor;
  }

}
