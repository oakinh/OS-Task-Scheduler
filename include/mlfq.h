#include <string>
#include <unordered_map>
#include <vector>
#include <task.h>
#include <memory>

class MLFQ {
    private:
        static constexpr int timeSlice = 10;
        int currentTime = 0;

        int queueLevels {};
        std::vector<std::vector<std::unique_ptr<Task>>> multiQueue {};

        Task* executing { nullptr };

        int currentLevel = 0;
        int currentIndex = 0;


        void MLFQ::runTick();

    public:
        MLFQ(int queueLevels = 3);
        void scheduleTask();
        void createTask(std::string_view name, int ticksToCompletion);
};