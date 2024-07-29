#include "Fighter.h"

#include <algorithm>

namespace rl {

  void Fighter::set_health(int hp)
  {
    health = std::max(0, std::min(hp, max_health));
  }


}
