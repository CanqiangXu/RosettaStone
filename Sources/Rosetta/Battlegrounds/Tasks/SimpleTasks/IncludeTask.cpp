// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Battlegrounds/Models/Player.hpp>
#include <Rosetta/Battlegrounds/Tasks/SimpleTasks/IncludeTask.hpp>

#include <stdexcept>

namespace RosettaStone::Battlegrounds::SimpleTasks
{
std::vector<std::reference_wrapper<Minion>> IncludeTask::GetMinions(
    EntityType entityType, [[maybe_unused]] Player& player, Minion& source)
{
    std::vector<std::reference_wrapper<Minion>> minions;

    switch (entityType)
    {
        case EntityType::SOURCE:
            minions.emplace_back(source);
            break;
        case EntityType::MINIONS:
            player.recruitField.ForEachAlive([&](MinionData& minion) {
                minions.emplace_back(minion.value());
            });
            break;
        case EntityType::STACK:
            minions = player.taskStack.minions;
            break;
        default:
            throw std::invalid_argument(
                "IncludeTask::GetEntities() - Invalid entity type");
    }

    return minions;
}
}  // namespace RosettaStone::Battlegrounds::SimpleTasks
