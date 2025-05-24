#include <task.h>

void Task::incrementWaitingTime() {
    ++this->waitingTime;
}

void Task::markArrival(const int clock) {
    this->arrivalTime = clock;
}

void Task::decrementTimeToExecute() {
    --this->ticksToCompletion;
}