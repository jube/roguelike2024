#ifndef RL_FIGHTER_H
#define RL_FIGHTER_H

namespace rl {
  struct Actor;

  struct Fighter {
    Fighter() = default;

    Fighter(int health, int defense, int power)
    : max_health(health)
    , health(health)
    , defense(defense)
    , power(power)
    {
    }

    int max_health = 0;
    int health = 0;
    int defense = 0;
    int power = 0;
  };


}


#endif // RL_FIGHTER_H
