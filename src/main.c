#include <stdio.h>
#include <string.h>
#include "task.h"
#include "tracker.h"
#include "utils.h"

int main(void) {
    Task tasks[MAX_TASKS];
    int count = 0;

    LOG("Daily Tracking - Create your task list");
    printf("Enter number of tasks: ");
    int n = read_positive_int();
    if (n <= 0 || n > MAX_TASKS) {
        ERR("Invalid number of tasks. Must be between 1 and %d.", MAX_TASKS);
        return 1;
    }

    // Collect task list
    for (int i = 0; i < n; i++) {
        char name[NAME_LEN];
        int mins;
        printf("Task %d name: ", i + 1);
        if (scanf("%63s", name) != 1) {
            ERR("Invalid task name input.");
            return 1;
        }
        printf("Time limit (minutes) for '%s': ", name);
        mins = read_positive_int();
        if (mins <= 0) {
            ERR("Invalid duration for '%s'. Must be positive.", name);
            return 1;
        }
        init_task(&tasks[count], name, mins);
        count++;
    }

    // Run sequential tracker (tick = 1 second)
    run_tracking_loop(tasks, count, 1);

    LOG("All tasks processed.");
    return 0;
}
