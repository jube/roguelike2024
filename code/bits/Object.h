#ifndef RL_OBJECT_H
#define RL_OBJECT_H

#include <gf2/core/Color.h>
#include <gf2/core/Vec2.h>

namespace rl {

  struct Object {
    gf::Vec2I position = { 0, 0 };
    char16_t character = ' ';
    gf::Color color = gf::White;
  };

}

#endif // RL_OBJECT_H
