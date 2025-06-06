#pragma once
#include <string>

class Task {
    public:
        int ticksToCompletion {};
        std::string name {};

        Task(const std::string taskName, int ticksToCompletion);
            

        void incrementWaitingTime();

        void markArrival(const int clock);

        void decrementTimeToExecute();
    private:
        int waitingTime {};
        int arrivalTime {};
        
};