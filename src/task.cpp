#include <task.h>

void Task::incrementWaitingTime() {
    ++waitingTime;
}

void Task::markArrival(const int clock) {
    arrivalTime = clock;
}

void Task::decrementTimeToExecute() {
    --ticksToCompletion;
}