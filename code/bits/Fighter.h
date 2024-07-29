#ifndef RL_FIGHTER_H
#define RL_FIGHTER_H

namespace rl {
  struct Actor;

  struct Fighter {
    int max_health = 0;
    int health = 0;
    int defense = 0;
    int power = 0;

    void set_health(int hp);
  };


}


#endif // RL_FIGHTER_H
