#ifndef RL_AI_H
#define RL_AI_H

#include <vector>
#include <variant>


#include <gf2/core/Vec2.h>

namespace rl {
  struct Actor;
  struct Map;

  struct HostileEnnemyAI {
    std::vector<gf::Vec2I> path;

    bool perform(Actor& self, Map& map);
  };


  struct AI {
    std::variant<std::monostate, HostileEnnemyAI> variant;

    bool perform(Actor& self, Map& map) {
      return std::visit([&](auto&& ai) {
        using T = std::decay_t<decltype(ai)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
          return true;
        } else {
          return ai.perform(self, map);
        }
      }, variant);
    }

    static AI hostile() {
      AI ai;
      ai.variant = HostileEnnemyAI();
      return ai;
    }

  };


}

#endif // RL_AI_H
