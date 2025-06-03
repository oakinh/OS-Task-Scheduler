#include <scheduler.h>
#include <iostream>
#include <sstream>
#include <util.h>

int main() {
    Scheduler* scheduler = new FIFO();
    
    std::cout << "Welcome to Nikao's OS Task Scheduler!" << std::endl;
    std::cout << "Let's schedule your first task..." << std::endl;

    bool gettingInput = true;
    while (gettingInput) {
        std::cout << "Please type 'done' without quotes when you're finished entering tasks" << std::endl;
        std::cout << "Please enter your task name and execution time: ";

        std::string line {};
        std::getline(std::cin, line);
        
        std::istringstream iss(line);
        std::string nameCandidate {};
        
        if (!(iss >> nameCandidate)) {
            std::cerr << "No input detected.\n";
            continue;
        }

        std::string possibleTermination = nameCandidate;
        toLower(possibleTermination);
        trim(possibleTermination);
        if (possibleTermination == "done") {
            break;
        }

        int ticksToCompletion {};

        if (!(iss >> ticksToCompletion)) {
            std::cerr << "Invalid format. Expected <taskName> <integer>\n";
            continue;
        }

        std::string leftover {};
        if (iss >> leftover) {
            std::cerr << "Extra data after integer" << leftover << "\"\n";
            continue;
        }
        scheduler->createTask(nameCandidate, ticksToCompletion);
        std::cout << "Task created successfully \n\n";
    }

    scheduler->printTasks();

    while (scheduler->hasTasks()) {
        scheduler->runTick();
    }

    return 0; 
}