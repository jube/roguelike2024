#ifndef RL_OBJECT_H
#define RL_OBJECT_H

#include <gf2/core/Color.h>
#include <gf2/core/Vec2.h>

namespace rl {

  class Object {
  public:
    Object() = default;

    Object(gf::Vec2I position, char16_t character, gf::Color color)
    : m_position(position)
    , m_character(character)
    , m_color(color)
    {
    }

    void set_position(gf::Vec2I position);
    gf::Vec2I position() const
    {
      return m_position;
    }

    char16_t character() const
    {
      return m_character;
    }

    gf::Color color() const
    {
      return m_color;
    }

    void move(gf::Vec2I displacement);

  private:
    gf::Vec2I m_position = { 0, 0 };
    char16_t m_character = ' ';
    gf::Color m_color = gf::White;
  };

}

#endif // RL_OBJECT_H
