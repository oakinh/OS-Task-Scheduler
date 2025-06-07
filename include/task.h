#pragma once
#include <string>

class Task {
    public:
        int ticksToCompletion {};
        int allotmentRemaining {};
        std::string name {};

        Task(const std::string taskName, int ticksToCompletion);
            

        void incrementWaitingTime();

        void markArrival(const int clock);

        void runTask();
    private:
        int waitingTime {};
        int arrivalTime {};
        
};