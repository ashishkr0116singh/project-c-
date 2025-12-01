#ifndef TASK_H
#define TASK_H

#include <time.h>
#include <stdbool.h>

#define MAX_TASKS 100
#define NAME_LEN 64

typedef struct {
    char name[NAME_LEN];
    int duration_minutes;         // total planned duration
    time_t start_time;            // when tracking began
    int elapsed_seconds;          // updated during tracking
    bool reminder_sent;           // half-time reminder flag
} Task;

void init_task(Task *t, const char *name, int duration_minutes);
double progress_percent(const Task *t);
double remaining_percent(const Task *t);
int remaining_seconds(const Task *t);
int total_seconds(const Task *t);

#endif  
