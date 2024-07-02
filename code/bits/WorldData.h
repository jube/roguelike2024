#ifndef RL_WORLD_DATA_H
#define RL_WORLD_DATA_H

#include <gf2/core/ActionData.h>

namespace rl {

  struct WorldData {
    WorldData();

    gf::ActionGroupData action_group;

  };

}

#endif // RL_WORLD_DATA_H
