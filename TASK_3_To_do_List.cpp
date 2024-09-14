#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 10;

struct Task {
    string text;
    string status = "pending";
};

Task tasks[MAX_TASKS];
int numTasks = 0;

void add_task(const string& text) {
    if (numTasks < MAX_TASKS) {
        tasks[numTasks++] = {text};
        cout << "Task added successfully." << endl;
    } else {
        cout << "Task list is full. Cannot add more tasks." << endl;
    }
}

void view_tasks() {
    if (numTasks == 0) {
        cout << "Task list is empty." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (int i = 0; i < numTasks; ++i) {
            cout << i + 1 << ". " << tasks[i].text << " - " << tasks[i].status << endl;
        }
    }
}

void mark_as_completed(int task_index) {
    if (task_index >= 1 && task_index <= numTasks) {
        tasks[task_index - 1].status = "completed";
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

void remove_task(int task_index) {
    if (task_index >= 1 && task_index <= numTasks) {
        for (int i = task_index - 1; i < numTasks - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        numTasks--;
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string text;
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, text);
                add_task(text);
                break;
            }
            case 2:
                view_tasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                mark_as_completed(index);
                break;
            }
            case 4: {
                int removeIndex;
                cout << "Enter task index to remove: ";
                cin >> removeIndex;
                remove_task(removeIndex);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}