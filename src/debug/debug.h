#ifndef DEBUG_H
#define DEBUG_H

typedef enum {
    DEBUG_LEVEL_INFO,
    DEBUG_LEVEL_WARN,
    DEBUG_LEVEL_ERROR
} DebugLevel;

// Initialisierung des Debug-Systems
void debug_init(void);

// Log-Ausgabe mit Level
void debug_log(DebugLevel level, const char* format, ...);

#endif // DEBUG_H
