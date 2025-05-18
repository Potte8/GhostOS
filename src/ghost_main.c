#include "src/ui_main_menu.h"
#include "debug.h"

int main(void) {
    debug_init();

    debug_log(DEBUG_LEVEL_INFO, "GhostOS gestartet");
    debug_log(DEBUG_LEVEL_WARN, "GPS Modul nicht gefunden");
    debug_log(DEBUG_LEVEL_ERROR, "WiFi Scan Fehler in module_wifi.c:118");

    return 0;
}
