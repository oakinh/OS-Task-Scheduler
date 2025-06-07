#include <task.h>

Task::Task(const std::string taskName, int ticksToCompletion) 
    : ticksToCompletion(ticksToCompletion), name(taskName) {}

void Task::incrementWaitingTime() {
    ++waitingTime;
}

void Task::markArrival(const int clock) {
    arrivalTime = clock;
}

void Task::runTask() {
    --ticksToCompletion;
    --allotmentRemaining;
}