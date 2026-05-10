# C++ To-Do List Application

A professional, console-based To-Do List application built with modern C++. This project strongly demonstrates Object-Oriented Programming (OOP) principles, efficient file handling, and reliable terminal user interaction.

## Features

- **Add Tasks with Priority**: Create new tasks assigned with High, Medium, or Low priority levels.
- **View Tasks Visually**: Display all tasks with color-coded priorities and completion statuses for high readability.
- **Mark Completed**: Easily check off tasks when they are done.
- **Delete Tasks**: Remove tasks you no longer need.
- **Search**: Do case-insensitive searches for specific tasks by a string keyword.
- **Statistics**: View your productivity stats including your total, completed, and pending tasks counts.
- **Persistent Storage**: Automatically saves your tasks data locally to `tasks.txt` and seamlessly loads them on startup.
- **Robust Input Handling**: Contains validation logic that elegantly handles invalid user inputs (out-of-range integers or wrong types) to strictly prevent app crashes.

## Technologies Used

- **C++17**
- **Standard Template Library (STL)**: `std::vector`, `std::string`, `std::algorithm`
- **File I/O**: `std::ifstream`, `std::ofstream`
- **ANSI Escape Codes**: Ensures a beautiful, colorized terminal output compatible with Linux/macOS.

## Compilation and Execution

To compile the application, ensure you have a C++ compiler installed locally (like `g++`).

Run the following command in your terminal inside the project root:

```bash
g++ -std=c++17 -Wall main.cpp Task.cpp TodoList.cpp -o todo_app
```

Then, you can seamlessly execute the application:

```bash
./todo_app
```

## Example Output

```text
===============================
      TO-DO LIST APP
===============================
1. Add Task
2. View All Tasks
3. Mark Task as Completed
4. Delete Task
5. Search Tasks
6. View Statistics
7. Save and Exit
-------------------------------
Choose an option (1-7): 2

--- Your Tasks ---
1. [TODO] [HIGH] Complete C++ Project
2. [DONE] [MED]  Read Documentation
3. [TODO] [LOW]  Buy Groceries
```

## Future Improvements

- Add due dates using the `<chrono>` library.
- Implement advanced sorting functionality (by priority, due date, or status).
- Expand support for multiple task lists (e.g., Work, Personal, Habits).
