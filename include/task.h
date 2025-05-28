#pragma once
#include <string>

class Task {
    public:
        int ticksToCompletion {};
        std::string name {};

        Task(const std::string& taskName, int ticks) 
            : ticksToCompletion(ticks), name(taskName), waitingTime(0), arrivalTime(0) {}

        void incrementWaitingTime();

        void markArrival(const int clock);

        void decrementTimeToExecute();
    private:
        int waitingTime {};
        int arrivalTime {};
        
};