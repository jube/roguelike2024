#ifndef RL_ROGUELIKE_H
#define RL_ROGUELIKE_H

#include <gf2/core/ResourceBundle.h>
#include <gf2/framework/SceneSystem.h>

#include "WorldScene.h"

namespace rl {

  class Roguelike : public gf::SceneSystem {
  public:
    Roguelike();

  private:
    gf::ResourceBundle world_bundle();

    std::unique_ptr<WorldScene> m_world_scene = nullptr;
  };

}

#endif // RL_ROGUELIKE_H
