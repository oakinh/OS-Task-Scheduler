#include <vector>
#include <queue>
#include <task.h>
#include <scheduler.h>
#include <iostream>
#include <typeinfo>
#include <memory>

////////////////
// Base Class //
////////////////

Scheduler::Scheduler() {}

void Scheduler::runTick() {
    clearCompleted();
    executeCurrentTask();
    scheduleTask();
    ++currentTime;
}

void Scheduler::executeCurrentTask() {
    if (executing) {
        executing->decrementTimeToExecute();
    } else {
        std::cerr << "Nothing to execute" << std::endl;
    }
}

void Scheduler::clearCompleted() {
    if (executing && executing->ticksToCompletion <= 0) {
        executing.reset();
    }
}

void Scheduler::scheduleTask() {
    return;
}

bool Scheduler::hasTasks() {
    if (!taskList.empty()) {
        std::cout << "All tasks completed" << std::endl;
        return false;
    }
    return true;
}

void Scheduler::createTask(std::string& name, int ticksToCompletion) {
    if (typeid(taskList) != typeid(std::vector<Task>)) {
        std::cerr << "Make sure addTasks is implemented for the corresponding data structure" << std::endl;
    }
    taskList.push_back(std::make_unique<Task>(name, ticksToCompletion));
}

//////////
// FIFO //
//////////

void FIFO::scheduleTask() {
    if (!executing && !taskQueue.empty()) {
        executing = std::move(taskList.front());
        taskQueue.pop();
    }
}

void FIFO::createTask(std::string& name, int ticksToCompletion) {
    taskQueue.push(std::make_unique<Task>(name, ticksToCompletion));
}