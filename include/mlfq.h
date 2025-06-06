#include <string>
#include <unordered_map>
#include <vector>
#include <task.h>
#include <memory>

class MLFQ {
    private:
        int queueLevels {};
        std::unordered_map<int, std::vector<std::unique_ptr<Task>>> multiQueue {};

    public:
        MLFQ(int queueLevels = 3);
        void scheduleTask();
        void createTask(std::string_view name, int ticksToCompletion);
};