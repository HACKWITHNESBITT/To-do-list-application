#include "TodoList.h"
#include <iostream>
#include <limits> // Included for std::numeric_limits

void displayMenu() {
    std::cout << CYAN << "\n===============================\n";
    std::cout << "      TO-DO LIST APP\n";
    std::cout << "===============================" << RESET << "\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View All Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Delete Task\n";
    std::cout << "5. Search Tasks\n";
    std::cout << "6. View Statistics\n";
    std::cout << "7. Save and Exit\n";
    std::cout << "-------------------------------\n";
    std::cout << "Choose an option (1-7): ";
}

// Reusable function to handle strict numeric input seamlessly
int getValidInput() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear(); // Clear the error state flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input characters
        std::cout << RED << "Invalid input. Please enter a number: " << RESET;
    }
    return choice;
}

int main() {
    TodoList lst("tasks.txt"); 
    int choice = 0;
    
    while (choice != 7) {
        displayMenu();
        choice = getValidInput();
        
        std::string title, keyword;
        int num, priority;
        
        switch (choice) {
            case 1:
                std::cout << "Enter task title: ";
                std::cin >> std::ws;
                std::getline(std::cin, title);
                
                std::cout << "Enter priority (1=High, 2=Medium, 3=Low): ";
                priority = getValidInput();
                if (priority < 1 || priority > 3) priority = 3; // Gracefully fallback to Low priority
                
                lst.add(title, priority);
                break;
            case 2:
                std::cout << CYAN << "\n--- Your Tasks ---\n" << RESET;
                lst.view();
                break;
            case 3:
                std::cout << "Enter task number to complete: ";
                num = getValidInput();
                lst.complete(num);
                break;
            case 4:
                std::cout << "Enter task number to delete: ";
                num = getValidInput();
                lst.del(num);
                break;
            case 5:
                std::cout << "Enter keyword to search: ";
                std::cin >> std::ws;
                std::getline(std::cin, keyword);
                std::cout << CYAN << "\n--- Search Results ---\n" << RESET;
                lst.search(keyword);
                break;
            case 6:
                std::cout << "\n";
                lst.displayStats();
                break;
            case 7:
                std::cout << "\nSaving tasks and exiting...\n";
                lst.save();
                std::cout << GREEN << "Goodbye!" << RESET << "\n";
                break;
            default:
                std::cout << RED << "Invalid option. Please choose between 1 and 7." << RESET << "\n";
        }
    }
    return 0;
}
