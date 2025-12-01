#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#define LOG(fmt, ...) fprintf(stdout, "[LOG] " fmt "\n", ##__VA_ARGS__)
#define ERR(fmt, ...) fprintf(stderr, "[ERR] " fmt "\n", ##__VA_ARGS__)

int clamp(int value, int min, int max);
int read_positive_int(void);
int seconds_from_minutes(int minutes);

#endif
