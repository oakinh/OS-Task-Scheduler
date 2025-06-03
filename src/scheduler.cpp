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
        std::cerr << "Nothing to execute\n";
    }
}

void Scheduler::clearCompleted() {
    if (executing && executing->ticksToCompletion <= 0) {
        std::cout 
            << "Task " 
            << executing->name 
            << " complete. Scheduling new task...\n";
        executing.reset();
        scheduleTask();
    }
}

void Scheduler::scheduleTask() {
    return;
}

bool Scheduler::hasTasks() {
    if (taskList.empty()) {
        std::cout << "All tasks completed\n";
        return false;
    }
    return true;
}

void Scheduler::printTasks() {
    if (taskList.empty()) {
        std::cout << "No tasks were found\n";
        return; 
    }
    for (size_t i = 0; i < taskList.size(); ++i) {
        if (taskList[i]) {
            std::cout 
                << i
                << ". " 
                << taskList[i]->name 
                << " | Execution Time: " 
                << taskList[i]->ticksToCompletion 
                << "\n";
        }
    }
}

void Scheduler::createTask(std::string& name, int ticksToCompletion) {
    static_assert(
        std::is_same_v<decltype(taskList),
            std::vector<std::unique_ptr<Task>>>,
            "Scheduler::taskList must be a vector of unique_ptr<Task>"
    );
    taskList.push_back(std::make_unique<Task>(name, ticksToCompletion));
    std::cout << "-> taskList.size() is now " << taskList.size() << "\n";
}

//////////
// FIFO //
//////////

void FIFO::scheduleTask() {
    if (!executing && !taskList.empty()) {
        executing = std::move(taskList.front());
        taskList.erase(taskList.begin());
        std::cout << "Scheduled FIFO style: " << executing->name << "\n";
    }
}
