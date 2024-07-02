#include "WorldData.h"

namespace rl {

  WorldData::WorldData()
  {
    using namespace gf::literals;

    action_group.actions.emplace("up"_id, gf::ActionData(gf::ActionType::Instantaneous).add_scancode_control(gf::Scancode::Up).add_scancode_control(gf::Scancode::W));
    action_group.actions.emplace("left"_id, gf::ActionData(gf::ActionType::Instantaneous).add_scancode_control(gf::Scancode::Left).add_scancode_control(gf::Scancode::A));
    action_group.actions.emplace("down"_id, gf::ActionData(gf::ActionType::Instantaneous).add_scancode_control(gf::Scancode::Down).add_scancode_control(gf::Scancode::S));
    action_group.actions.emplace("right"_id, gf::ActionData(gf::ActionType::Instantaneous).add_scancode_control(gf::Scancode::Right).add_scancode_control(gf::Scancode::D));

  }

}
