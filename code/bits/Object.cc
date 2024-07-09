#include "Object.h"

namespace rl {

  void Object::move(gf::Vec2I displacement)
  {
    m_position += displacement;
  }


}
