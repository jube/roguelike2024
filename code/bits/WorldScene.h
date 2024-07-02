#ifndef RL_WORLD_SCENE_H
#define RL_WORLD_SCENE_H

#include <gf2/core/ConsoleData.h>
#include <gf2/graphics/ConsoleEntity.h>
#include <gf2/graphics/ConsoleFont.h>
#include <gf2/graphics/Scene.h>

#include "WorldState.h"

namespace rl {
  class Roguelike;

  class WorldScene : public gf::Scene {
  public:
    WorldScene(Roguelike* game);

  private:
    void do_update(gf::Time time) override;

    Roguelike* m_game = nullptr;

    gf::ConsoleData m_root_console;

    gf::ConsoleFont* m_console_font = nullptr;
    gf::ConsoleEntity m_console_entity;

    WorldState m_state;
  };

}

#endif // RL_WORLD_SCENE_H
