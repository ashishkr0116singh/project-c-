#include <string.h>
#include "task.h"
#include "utils.h"

void init_task(Task *t, const char *name, int duration_minutes) {
    if (!t || !name || duration_minutes <= 0) return;
    strncpy(t->name, name, NAME_LEN - 1);
    t->name[NAME_LEN - 1] = '\0';
    t->duration_minutes = duration_minutes;
    t->start_time = 0;
    t->elapsed_seconds = 0;
    t->reminder_sent = false;
}

int total_seconds(const Task *t) {
    return seconds_from_minutes(t->duration_minutes);
}

int remaining_seconds(const Task *t) {
    int remain = total_seconds(t) - t->elapsed_seconds;
    return remain < 0 ? 0 : remain;
}

double progress_percent(const Task *t) {
    int total = total_seconds(t);
    if (total <= 0) return 0.0;
    double pct = (double)t->elapsed_seconds * 100.0 / (double)total;
    if (pct < 0) pct = 0;
    if (pct > 100) pct = 100;
    return pct;
}

double remaining_percent(const Task *t) {
    return 100.0 - progress_percent(t);
}
