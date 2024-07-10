#include "Object.h"

namespace rl {

  void Object::set_position(gf::Vec2I position)
  {
    m_position = position;
  }

  void Object::move(gf::Vec2I displacement)
  {
    m_position += displacement;
  }

}
