#include "log_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char* current_log = NULL;

void log_manager_init(void) {
    // Init Log-Manager (z.B. Speicher reservieren)
}

bool log_manager_load_log(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return false;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (current_log) free(current_log);
    current_log = malloc(size + 1);
    if (!current_log) {
        fclose(f);
        return false;
    }

    fread(current_log, 1, size, f);
    current_log[size] = '\0';

    fclose(f);
    return true;
}

void log_manager_filter_logs(const char* level) {
    if (!current_log) return;

    char* line = strtok(current_log, "\n");
    while (line) {
        if (!level || strstr(line, level)) {
            printf("%s\n", line);
        }
        line = strtok(NULL, "\n");
    }
}
