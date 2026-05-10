#include "TodoList.h"
#include <iostream>
#include <fstream>
#include <algorithm> // For std::transform used in search

TodoList::TodoList(std::string file) : filename(file) {
    load(); // Auto-load tasks when app starts
}

void TodoList::load() {
    std::ifstream f(filename);
    if (!f) return; // Silent return if file doesn't exist yet

    std::string t; 
    bool d;
    int p;
    
    // Safely reads the structure: [done status] [priority] [title]
    while(f >> d >> p && getline(f >> std::ws, t)) {
        tasks.push_back(Task(t, p, d));
    }
}

void TodoList::save() const {
    std::ofstream f(filename);
    for(const auto& t : tasks) {
        f << t.isDone() << " " << t.getPriority() << " " << t.getTitle() << "\n";
    }
    std::cout << CYAN << "Tasks successfully saved to " << filename << RESET << "\n";
}

void TodoList::add(std::string t, int priority) { 
    tasks.push_back(Task(t, priority)); 
    std::cout << GREEN << "Success: Task added!" << RESET << "\n";
}

void TodoList::view() const {
    if (tasks.empty()) {
        std::cout << YELLOW << "Your To-Do list is currently empty!" << RESET << "\n";
        return;
    }
    
    for(size_t i = 0; i < tasks.size(); i++) { 
        std::cout << i + 1 << ". "; 
        tasks[i].display(); 
    }
}

void TodoList::complete(int i) { 
    // Boundary checking to prevent out-of-range errors
    if(i > 0 && i <= static_cast<int>(tasks.size())) {
        tasks[i - 1].complete(); 
        std::cout << GREEN << "Success: Task marked as completed!" << RESET << "\n";
    } else {
        std::cout << RED << "Error: Invalid task number!" << RESET << "\n";
    }
}

void TodoList::del(int i) { 
    if(i > 0 && i <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + i - 1); 
        std::cout << GREEN << "Success: Task deleted!" << RESET << "\n";
    } else {
        std::cout << RED << "Error: Invalid task number!" << RESET << "\n";
    }
}

void TodoList::search(std::string keyword) const {
    bool found = false;
    std::string lowerKeyword = keyword;
    // Convert search term to lowercase
    std::transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);

    for (size_t i = 0; i < tasks.size(); i++) {
        std::string lowerTitle = tasks[i].getTitle();
        // Convert task title to lowercase for case-insensitive search
        std::transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
        
        if (lowerTitle.find(lowerKeyword) != std::string::npos) {
            std::cout << i + 1 << ". ";
            tasks[i].display();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << YELLOW << "No tasks found matching: '" << keyword << "'" << RESET << "\n";
    }
}

void TodoList::displayStats() const {
    int total = tasks.size();
    int completed = 0;
    
    for (const auto& t : tasks) {
        if (t.isDone()) completed++;
    }
    
    std::cout << CYAN << "--- Task Statistics ---" << RESET << "\n";
    std::cout << "Total Tasks  : " << total << "\n";
    std::cout << GREEN << "Completed    : " << completed << RESET << "\n";
    std::cout << YELLOW << "Pending      : " << (total - completed) << RESET << "\n";
    std::cout << "-----------------------\n";
}
