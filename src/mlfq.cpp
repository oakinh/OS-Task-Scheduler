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
        this->multiQueue[i] = std::vector<std::unique_ptr<Task>>{};
    }
}

void MLFQ::scheduleTask() {

}

void MLFQ::createTask(std::string_view name, int ticksToCompletion) {\
    // All tasks enter at highest priority
    multiQueue[0].push_back(std::make_unique<Task>(std::string(name), ticksToCompletion));
}