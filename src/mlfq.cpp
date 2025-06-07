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
        this->executing->runTask();
    } else {
        std::cerr << "Error, no task to execute\n";
    }
    if (
        this->executing->ticksToCompletion <= 0 || 
        this->currentTime % this->timeSlice == 0
    ) {
        scheduleTask();
    }
}

void MLFQ::scheduleTask() {
    // If there's anything on a higher priority level, change to that level
    if (!this->executing->ticksToCompletion <= 0) {
        // Not completed yet
        if (auto& uptr = multiQueue[currentLevel].front(); uptr) {

            if (
            uptr->allotmentRemaining <= 0 &&
            currentLevel < multiQueue.size() - 1 // True: not the last level
            ) {
                // Move to next level down
                int nextLevel = currentLevel++;
                uptr->allotmentRemaining = baseAllotment * (1 << nextLevel);
                multiQueue[nextLevel].push_back((uptr)); // TODO: std::move or no?
                multiQueue[currentLevel].pop_front();
                // Set allotment
            } else {

            }
            return;
        }
        
        
    }
    // Task is done, schedule a new one
    std::cout << "Task: " << this->executing->name << " is complete\n";
    this->executing == nullptr;
    multiQueue[currentLevel].pop_front();
    if (!multiQueue[currentLevel].empty()) {
        this->executing = multiQueue[currentLevel].front().get(); 
    }
}

void MLFQ::createTask(std::string_view name, int ticksToCompletion) {
    // All tasks enter at highest priority
    multiQueue[0].push_back(std::make_unique<Task>(std::string(name), ticksToCompletion));
}