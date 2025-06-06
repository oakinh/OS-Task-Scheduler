#include <string>
#include <mlfq.h>
#include <task.h>
#include <memory>
#include <iostream>
#include <string>
#include <string_view>

MLFQ::MLFQ(int queueLevels) : queueLevels(queueLevels) {
    if (queueLevels <= 0) {
        std::cerr << "Invalid number of queue levels, defaulting to 3. \n";
        this->queueLevels = 3;
    }

    for (int i = 0; i < queueLevels; ++i) {
        this->multiQueue.push_back({});
    }
}

void MLFQ::runTick() {
    ++this->currentTime;
    if (this->executing) {
        this->executing->decrementTimeToExecute();
        if (this->executing->ticksToCompletion <= 0) {
            std::cout << this->executing->name << " has finished executing\n";
            this->multiQueue[this->currentLevel][this->currentIndex] = nullptr;
            
        }
    } else {
        std::cerr << "Error, no task to execute\n";
    }
    if (this->currentTime % this->timeSlice == 0) {
        scheduleTask();
    }
}

void MLFQ::scheduleTask() {

}

void MLFQ::createTask(std::string_view name, int ticksToCompletion) {
    // All tasks enter at highest priority
    multiQueue[0].push_back(std::make_unique<Task>(std::string(name), ticksToCompletion));
}