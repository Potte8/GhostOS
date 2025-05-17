#include <stdio.h>
#include "log_manager.h"

void log_viewer_show(const char* filename, const char* filter) {
    if (!log_manager_load_log(filename)) {
        printf("Fehler: Datei %s konnte nicht geladen werden.\n", filename);
        return;
    }

    printf("=== Log Datei: %s ===\n", filename);
    log_manager_filter_logs(filter);
}

int main(void) {
    log_viewer_show("logs/2025-05-17.log", NULL);
    return 0;
}
