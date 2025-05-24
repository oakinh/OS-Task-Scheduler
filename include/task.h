#pragma once

class Task {
    public:
        int ticksToCompletion {};
        void incrementWaitingTime();

        void markArrival(const int clock);

        void decrementTimeToExecute();
    private:
        int waitingTime {};
        int arrivalTime {};
        
};