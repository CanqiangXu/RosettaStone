// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// Hearthstone++ is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_ENQUEUE_TASK_HPP
#define ROSETTASTONE_ENQUEUE_TASK_HPP

#include <Rosetta/Tasks/Tasks.hpp>

namespace RosettaStone::SimpleTasks
{
//!
//! \brief EnqueueTask class.
//!
//! This class represents the task for repeating some tasks.
//!
class EnqueueTask : public ITask
{
 public:
    //! Constructs task with given \p tasks and \p num.
    //! \param tasks A task vector to repeat.
    //! \param num The number of times to repeat tasks.
    EnqueueTask(std::vector<ITask*> tasks, int num);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    TaskStatus Impl(Player& player) override;

    std::vector<ITask*> m_tasks;
    int m_num = 0;
};
}  // namespace RosettaStone::SimpleTasks

#endif  // ROSETTASTONE_ENQUEUE_TASK_HPP
