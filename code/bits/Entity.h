#ifndef RL_ENTITY_H
#define RL_ENTITY_H

#include <string>

#include <gf2/core/Color.h>
#include <gf2/core/Vec2.h>

namespace rl {

  struct Entity {
    gf::Vec2I position = { 0, 0 };
    char16_t character = ' ';
    gf::Color color = gf::White;
    std::string name;
    bool blocks_movement = false;
  };

}

#endif // RL_ENTITY_H
