#ifndef RL_ROGUELIKE_H
#define RL_ROGUELIKE_H

#include <gf2/core/ResourceBundle.h>
#include <gf2/framework/SceneSystem.h>

#include "WorldScene.h"

namespace rl {

  struct Roguelike : gf::SceneSystem {
    Roguelike();


    WorldScene world_scene;


    gf::ResourceBundle world_bundle();
  };

}

#endif // RL_ROGUELIKE_H
