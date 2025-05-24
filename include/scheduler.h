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
        std::vector<Task> taskList {};

    public:
        Task* executing = nullptr;
        int currentTime = 0;

        void runTick();
        virtual bool hasTasks();
        virtual void addTasks(std::vector<Task> tasks);

        
        
        virtual ~Scheduler() {};
};

//////////
// FIFO //
//////////

class FIFO : public Scheduler {
    protected:
        std::queue<Task> taskList{};
        
    public:
        void scheduleTask() override;
        void addTasks(std::vector<Task>) override;
};