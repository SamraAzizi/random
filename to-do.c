#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 50

typedef struct {
    char task[MAX_TASK_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(const char *task) {
    if (numTasks < MAX_TASKS) {
        strcpy(tasks[numTasks].task, task);
        tasks[numTasks].completed = 0;
        numTasks++;
        printf("Task added successfully.\n");
    } else {
        printf("Cannot add task. Maximum tasks reached.\n");
    }
}

void markCompleted(int index) {
    if (index >= 0 && index < numTasks) {
        tasks[index].completed = 1;
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void displayTasks() {
    printf("To-Do List:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "X" : " ", tasks[i].task);
    }
}

int main() {
    int choice;
    char newTask[MAX_TASK_LENGTH];

    while (1) {
        printf("\n1. Add Task\n2. Mark Task as Completed\n3. Display Tasks\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the task: ");
                scanf(" %[^\n]", newTask);
                addTask(newTask);
                break;
            case 2:
                if (numTasks > 0) {
                    displayTasks();
                    printf("Enter the index of the task to mark as completed: ");
                    int index;
                    scanf("%d", &index);
                    markCompleted(index - 1);
                } else {
                    printf("No tasks to mark as completed.\n");
                }
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
