Explanation of Todo List program Functioning

1.Explain that the program simulates a simple Todo list management system using a class called Todo.

2.Describe the methods available in the Todo class:
	AddTask: Adds a task to the list if it's not a duplicate.
	RemoveTask: Removes a task by its task number.
	MarkTask: Marks a task as complete by its task number.
	EmptyTasks: Removes all tasks from the list.	
	Display: Clears the console and displays all tasks in the list.

3.Explain how the main function interacts with the Todo class:
	Creates an instance of the Todo class.
	Displays available commands and enters a loop to process user commands.
	Handles user input for adding, removing, marking, displaying tasks, and emptying the task list.
4.Highlight any input handling techniques, such as cin.ignore() and getline(), used to handle spaces in task descriptions.

5.Include any additional information or insights you think would be helpful for someone understanding and using your program.

____________________________
Code Includes the Following:

Todo Class:

	The Todo class is defined to manage a list of tasks.
	It has a private member TaskList of type vector<string> to store the tasks.
	AddTask Method:

The AddTask method takes a task description as a parameter.
	It checks if the task is not already present in the TaskList. If it's not present, it adds the task to the list and sets 	CanBeAdded to true.
	If the task already exists, it sets CanBeAdded to false.
	If CanBeAdded is true, the task is added to TaskList.
	RemoveTask Method:

The RemoveTask method takes the task number to remove as a parameter.
	It checks if the given task number is valid within the range of the TaskList.
	If valid, it shifts tasks to overwrite the removed task and resizes the list.
	MarkTask Method:

The MarkTask method takes the task number to mark as complete as a parameter.
	It checks if the given task number is valid within the range of the TaskList.
	If valid, it modifies the task's status to "Complete."
	EmptyTasks Method:

The EmptyTasks method clears the TaskList, effectively removing all tasks.
Display Method:

The Display method clears the console screen and displays all tasks in the TaskList.
Main Function:

In the main function, an instance of the Todo class, T1, is created.
It displays available commands and enters a loop to process user commands until the user enters "exit."
Depending on the entered command, it performs the corresponding action using the methods of the Todo class.
Input Handling:

In the "tskadd" block, a loop allows users to input tasks continuously until they enter "exit."
The cin.ignore() before the loop clears any newline characters from the buffer.
The getline(cin, task) is used to correctly input tasks with spaces