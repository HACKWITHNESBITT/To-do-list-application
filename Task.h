#ifndef TASK_H
#define TASK_H
#include <string>

// ANSI Color codes for terminal output to make the UI look professional
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";

class Task {
private:
    std::string title;
    bool done;
    int priority; // 1: High, 2: Medium, 3: Low

public:
    // Constructor with default arguments for flexibility
    Task(std::string t, int p = 3, bool d = false) : title(t), done(d), priority(p) {}
    
    // Core functional methods
    void display() const;
    void complete() { done = true; }
    
    // Getters for encapsulation
    std::string getTitle() const { return title; }
    bool isDone() const { return done; }
    int getPriority() const { return priority; }
    
    // Helper methods
    std::string getPriorityString() const;
};
#endif
