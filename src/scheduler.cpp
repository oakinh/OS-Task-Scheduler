#include <vector>
#include <queue>
#include <task.h>
#include <scheduler.h>
#include <iostream>
#include <typeinfo>

////////////////
// Base Class //
////////////////

Scheduler::Scheduler() {}

void Scheduler::runTick() {
    this->executeCurrentTask();
    this->clearCompleted();
    this->scheduleTask();
    ++currentTime;
}

void Scheduler::executeCurrentTask() {
    if (executing != nullptr) {
        executing->decrementTimeToExecute();
    } else {
        std::cerr << "Nothing to execute" << std::endl;
    }
}

void Scheduler::clearCompleted() {
    if (executing->ticksToCompletion == 0) {
        executing = nullptr;
    }
}

void Scheduler::scheduleTask() {
    return;
}

bool Scheduler::hasTasks() {
    if (!this->taskList.empty()) {
        std::cout << "All tasks completed" << std::endl;
        return false;
    }
    return true;
}

void Scheduler::addTasks(std::vector<Task> tasks) {
    if (typeid(this->taskList) != typeid(std::vector<Task>)) {
        std::cerr << "Make sure addTasks is implemented for the corresponding data structure" << std::endl;
    }
    for (auto task : tasks) {
        this->taskList.push_back(task);
    }
}

//////////
// FIFO //
//////////

void FIFO::scheduleTask() {
    if (taskList.size() != 0) {
        executing = &taskList.front();
        taskList.pop();
    }
}

void FIFO::addTasks(std::vector<Task> tasks) {
    for (auto task : tasks) {
        this->taskList.push(task);
    }
}