#ifndef TRACKER_H
#define TRACKER_H

#include "task.h"

void start_task(Task *t);
void update_task(Task *t, int tick_seconds);
void maybe_send_half_reminder(Task *t);
void print_task_status(const Task *t);
void run_tracking_loop(Task *tasks, int count, int tick_seconds);

#endif
