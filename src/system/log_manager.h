#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <stdbool.h>

void log_manager_init(void);
bool log_manager_load_log(const char* filename);
void log_manager_filter_logs(const char* level);  // "ERROR", "WARN", "INFO" oder NULL für alles

#endif // LOG_MANAGER_H
