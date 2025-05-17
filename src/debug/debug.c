#include "debug.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

static const char* level_strings[] = {"INFO", "WARN", "ERROR"};

void debug_init(void) {
    printf("Debug-System initialisiert\n");
}

void debug_log(DebugLevel level, const char* format, ...) {
    va_list args;
    va_start(args, format);

    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char timestamp[20];
    snprintf(timestamp, sizeof(timestamp), "%04d-%02d-%02d %02d:%02d:%02d",
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
             t->tm_hour, t->tm_min, t->tm_sec);

    printf("[%s] [%s] ", timestamp, level_strings[level]);
    vprintf(format, args);
    printf("\n");

    va_end(args);
}
