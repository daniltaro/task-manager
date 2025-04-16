# Task Manager

A terminal-based task manager application that allows users to add, view, sort, delete, and display tasks in a file.

## Features:
- **Write**: Add a new task with a specified priority (1-10).
- **Read**: Display all tasks stored in the file.
- **Sort**: Sort tasks by priority in ascending order.
- **Unsort**: Display tasks in the order they were added (unsorted).
- **Delete**: Remove a task by its ID.

## Requirements:
- **C++11 or later**.

## Usage:

1. **Run the Program**:  
   Compile and run the program in your terminal.

2. **Provide a Filename**:  
   Enter the filename where tasks will be stored. If the file already exists and contains tasks, you will be prompted whether to clear it or not.

3. **Select Actions**:  
   The program will prompt you to choose from the following actions:
    - **write**: Add a new task.
    - **read**: View all tasks in the file.
    - **sort**: Sort tasks by priority.
    - **unsort**: View tasks in the order they were added.
    - **delete**: Delete a task by its ID.

4. **Add Tasks**:  
   When choosing to **write** a task, you will be asked to enter the task description and its priority (1-10). The task will be added to the list and saved to the file.

5. **Sorting and Unsorting**:  
   Tasks can be sorted by priority or displayed in the order they were added.

6. **Delete Tasks**:  
   To delete a task, simply provide the task ID when prompted.

## Example Interaction:
```
Write filename: tasks.txt
Do you want to clear file? y/n: n
Choose write/read/unsort/sort/delete tasks: write
Write task: Buy groceries
Write priority (1-10): 5
Choose write/read/unsort/sort/delete tasks: read
	1.	Buy groceries. priority - (5)
Choose write/read/unsort/sort/delete tasks: sort
Choose write/read/unsort/sort/delete tasks: delete
Write task number: 1
```

## File Format:
The tasks are saved in a text file with the following format:

	1.	Task description. priority - (priority_number)

### Notes:
- Tasks are saved in a file and can be manipulated (sorted, deleted, etc.) based on their priority or order.
- Tasks are identified by an ID, which is automatically assigned when a task is created.
  
