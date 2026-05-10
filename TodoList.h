#ifndef TODOLIST_H
#define TODOLIST_H
#include "Task.h"
#include <vector>

class TodoList {
private:
    std::vector<Task> tasks;
    std::string filename;

public:
    // Constructor initializes list and automatically loads saved tasks
    TodoList(std::string file = "tasks.txt");
    
    // Core operations
    void add(std::string t, int priority);
    void view() const;
    void complete(int i);
    void del(int i);
    
    // Storage operations
    void save() const;
    void load();
    
    // Advanced features
    void search(std::string keyword) const;
    void displayStats() const;
};
#endif
