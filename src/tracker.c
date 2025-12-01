#include <stdio.h>
#include <time.h>
#include <unistd.h> // for sleep
#include "tracker.h"
#include "utils.h"

void start_task(Task *t) {
    if (!t) return;
    t->start_time = time(NULL);
    t->elapsed_seconds = 0;
    t->reminder_sent = false;
    LOG("Started task '%s' for %d minutes.", t->name, t->duration_minutes);
}

void update_task(Task *t, int tick_seconds) {
    if (!t) return;
    t->elapsed_seconds += tick_seconds;
    int total = total_seconds(t);
    if (t->elapsed_seconds > total) {
        t->elapsed_seconds = total;
    }
}

void maybe_send_half_reminder(Task *t) {
    if (!t) return;
    int total = total_seconds(t);
    int half = total / 2;
    // Send reminder once when elapsed crosses half
    if (!t->reminder_sent && t->elapsed_seconds >= half) {
        t->reminder_sent = true;
        LOG("Reminder: You're halfway through '%s'. Keep going!", t->name);
    }
}

void print_task_status(const Task *t) {
    printf("Task: %s | Progress: %.1f%% | Left: %.1f%% | Remaining: %d sec\n",
           t->name, progress_percent(t), remaining_percent(t), remaining_seconds(t));
}

void run_tracking_loop(Task *tasks, int count, int tick_seconds) {
    if (!tasks || count <= 0) return;

    for (int i = 0; i < count; i++) {
        Task *t = &tasks[i];
        start_task(t);
        while (remaining_seconds(t) > 0) {
            print_task_status(t);
            maybe_send_half_reminder(t);
            sleep(tick_seconds);
            update_task(t, tick_seconds);
        }
        print_task_status(t);
        LOG("Completed task '%s'.", t->name);
        puts("------------------------------");
    }
}
