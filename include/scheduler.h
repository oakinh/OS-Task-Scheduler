#pragma once
#include <vector>
#include <queue>
#include <task.h>

////////////////
// Base Class //
////////////////

class Scheduler {
    protected:
        void executeCurrentTask();
        void clearCompleted();
        virtual void Scheduler::scheduleTask();
        
        int throughput {};
        std::vector<std::unique_ptr<Task>> taskList {};

    public:
        std::unique_ptr<Task> executing {};
        int currentTime = 0;

        void runTick();
        virtual bool hasTasks();
        virtual void createTask(std::string& name, int ticksToCompletion);

        
        
        virtual ~Scheduler() {};
};

//////////
// FIFO //
//////////

class FIFO : public Scheduler {
    protected:
        std::queue<std::unique_ptr<Task>> taskQueue{};
        
    public:
        void scheduleTask() override;
        void createTask(std::string& name, int ticksToCompletion) override;
};