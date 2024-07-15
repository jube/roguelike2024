#ifndef RL_WORLD_SCENE_H
#define RL_WORLD_SCENE_H

#include <gf2/core/ConsoleBuffer.h>
#include <gf2/graphics/ActionGroup.h>
#include <gf2/graphics/ConsoleEntity.h>
#include <gf2/graphics/ConsoleFont.h>
#include <gf2/graphics/Scene.h>

#include "WorldData.h"
#include "WorldState.h"

namespace rl {
  class Roguelike;

  class WorldScene : public gf::Scene {
  public:
    WorldScene(Roguelike* game);

  private:
    void do_process_event(const gf::Event& event) override;
    void do_handle_actions() override;
    void do_update(gf::Time time) override;

    Roguelike* m_game = nullptr;
    WorldData m_data;
    WorldState m_state;

    gf::ActionGroup m_action_group;

    gf::ConsoleBuffer m_root_console;

    gf::ConsoleFont* m_console_font = nullptr;
    gf::ConsoleEntity m_console_entity;

  };

}

#endif // RL_WORLD_SCENE_H
