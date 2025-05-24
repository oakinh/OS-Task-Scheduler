#pragma once
#include <string>

class Task {
    public:
        int ticksToCompletion {};
        std::string name {};

        void incrementWaitingTime();

        void markArrival(const int clock);

        void decrementTimeToExecute();
    private:
        int waitingTime {};
        int arrivalTime {};
        
};