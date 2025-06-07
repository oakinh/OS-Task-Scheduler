#include <string>
#include <unordered_map>
#include <vector>
#include <task.h>
#include <memory>
#include <deque>

class MLFQ {
    private:
        static constexpr int timeSlice = 10;
        static constexpr int baseAllotment = 10;
        int currentTime = 0;
        int currentLevel = 0;

        int queueLevels {};
        std::vector<std::deque<std::unique_ptr<Task>>> multiQueue {};

        Task* executing { nullptr };
        
        void scheduleTask();

    public:
        MLFQ(int queueLevels = 3);
        void MLFQ::runTick();
        void createTask(std::string_view name, int ticksToCompletion);
};