#pragma once
#include <vector>
#include <queue>
#include <task.h>
#include <memory>

////////////////
// Base Class //
////////////////

class Scheduler {
    protected:
        void executeCurrentTask();
        void clearCompleted();
        virtual void scheduleTask();
        
        int throughput {};
        std::vector<std::unique_ptr<Task>> taskList {};

    public:
        std::unique_ptr<Task> executing {};
        int currentTime = 0;

        void runTick();
        virtual bool hasTasks();
        void createTask(std::string& name, int ticksToCompletion);
        void printTasks();

        
        Scheduler() {};
        virtual ~Scheduler() {};
};

//////////
// FIFO //
//////////

class FIFO : public Scheduler {
    public:
        void scheduleTask() override;
};