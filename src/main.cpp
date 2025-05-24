#include <scheduler.h>
#include <iostream>
#include <sstream>

int main() {
    Scheduler* scheduler = new FIFO();
    
    std::cout << "Welcome to Nikao's OS Task Scheduler!" << std::endl;
    std::cout << "Let's schedule your first task..." << std::endl;
    std::cout << "Please enter your task name and execution time: ";

    std::string line {};
    std::getline(std::cin, line);
    
    std::istringstream iss(line);
    std::string taskName {};
    int ticksToCompletion {};

    if (iss >> taskName >> ticksToCompletion) {
        std::cout << "Task name: " << taskName << "Execution Time: " << ticksToCompletion << std::endl;
    } else {
        std::cerr << "Invalid input" << std::endl;
    }

    return 0;
}