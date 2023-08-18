#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Todo
{
private:
    vector<string> TaskList;

public:
    // Adds Tasks
    void AddTask(string task)
    {
        bool CanBeAdded = true;
        task += "     Status: Incomplete";
        for (const auto &tasks : TaskList)
        {
            if (tasks == task)
            {
                CanBeAdded = false;
                break;
            }
        }
        if (CanBeAdded)
        {
            TaskList.push_back(task);
            cout << "Task added successfully." << endl;
        }
        else
        {
            cout << "Requested task can't be Added Due to Repetation" << endl;
        }
    }
    // RemoveTasks
    void RemoveTask(int TaskNum)
    {
        if (TaskNum >= 0 && TaskNum < TaskList.size())
        {
            for (int i = TaskNum; i < TaskList.size() - 1; i++)
            {
                TaskList[i] = TaskList[i + 1];
            }
            TaskList.resize(TaskList.size() - 1);
            cout << "Task removed successfully." << endl;
        }
        else
        {
            cout << "Such Task Number Does't Exits." << endl;
        }
    }
    // Mark incomplete tasks to complete
    void MarkTask(int TaskNum)
    {
        string str;
        if (TaskNum >= 0 && TaskNum < TaskList.size())
        {
            for (int i = 0; i < TaskList[TaskNum].size() - 10; i++)
            {
                str += TaskList[TaskNum][i];
            }
            str += "Complete";
            TaskList[TaskNum] = str;
            cout << "Task marked as complete." << endl;
        }
        else
        {
            cout << "Such Task Number Does't Exits." << endl;
        }
    }
    // Empty the Task List
    void EmptyTasks()
    {
        TaskList.clear();
        cout << "All tasks have been removed." << endl;
    }
    // Display All Tasks
    void Display()
    {
        system("cls");
        if (TaskList.empty())
        {
            cout << "No task Found" << endl;
        }
        for (const auto &str : TaskList)
        {
            cout << str << endl;
        }
    }
};

int main()
{
    Todo T1;
    string cmd;
    cout << "Welcome to Todo CLI" << endl
         << "Available Commands:" << endl
         << "tskadd    --> Add a new task" << endl
         << "tskremove --> Remove a specific task" << endl
         << "tskmrk    --> Mark a task as complete" << endl
         << "tskdis    --> Display all tasks" << endl
         << "tskempty  --> Empty the task list" << endl
         << "exit      --> Exit the program" << endl;

    while (cmd != "exit")
    {
        cout << "Enter a command: ";
        cin >> cmd;

        if (cmd == "tskadd")
        {

            cout << "Enter exit to stop Adding the tasks" << endl;
            cin.ignore();
            while (1)
            {
                string task = "";
                cout << "Enter task description: ";
                getline(cin, task);
                if (task == "exit")
                {
                    cout << "Program Stopped Adding tasks" << endl;
                    break;
                }
                T1.AddTask(task);
            }
        }
        else if (cmd == "tskremove")
        {
            int taskNumber;
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            T1.RemoveTask(taskNumber - 1);
        }
        else if (cmd == "tskmrk")
        {
            int taskNumber;
            cout << "Enter task number to mark as complete: ";
            cin >> taskNumber;
            T1.MarkTask(taskNumber - 1);
        }
        else if (cmd == "tskdis")
        {
            T1.Display();
        }
        else if (cmd == "tskempty")
        {
            T1.EmptyTasks();
        }
        else if (cmd != "exit")
        {
            cout << "Invalid command. Please recheck your input." << endl;
        }
    }

    return 0;
}
