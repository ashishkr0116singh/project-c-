#include "utils.h"

int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

int read_positive_int(void) {
    int x;
    if (scanf("%d", &x) != 1) return -1;
    return x > 0 ? x : -1;
}

int seconds_from_minutes(int minutes) {
    return minutes * 60;
}
