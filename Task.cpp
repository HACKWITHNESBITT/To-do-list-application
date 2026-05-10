#include "Task.h"
#include <iostream>

// Helper to convert priority integer to a readable string format
std::string Task::getPriorityString() const {
    if (priority == 1) return "[HIGH]";
    if (priority == 2) return "[MED] ";
    return "[LOW] ";
}

// Displays the task beautifully using ANSI colors based on completion and priority
void Task::display() const {
    if (done) {
        // Completed tasks are uniformly green
        std::cout << GREEN << "[DONE] " << getPriorityString() << " " << title << RESET << "\n";
    } else {
        // Pending tasks have varying colors based on priority
        if (priority == 1) {
            std::cout << RED << "[TODO] " << getPriorityString() << " " << title << RESET << "\n"; // High priority
        } else {
            std::cout << YELLOW << "[TODO] " << getPriorityString() << " " << title << RESET << "\n"; // Med/Low priority
        }
    }
}
