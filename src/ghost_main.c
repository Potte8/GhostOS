#include "src/ui_main_menu.h"
#include "debug.h"
#include <stdio.h>

// Temporäre Eingabefunktion (kann später ersetzt werden mit echten Tasten)
int get_user_input() {
    char c = getchar();
    switch (c) {
        case 'w': return 1; // Hoch
        case 's': return 2; // Runter
        case 'e': return 3; // OK
        default: return 0;
    }
}

int main(void) {
    // Debug-System starten
    debug_init();
    debug_log(DEBUG_LEVEL_INFO, "GhostOS gestartet");
    debug_log(DEBUG_LEVEL_WARN, "GPS Modul nicht gefunden");
    debug_log(DEBUG_LEVEL_ERROR, "WiFi Scan Fehler in module_wifi.c:118");

    // Menüsystem starten
    ui_main_menu_init();

    while (1) {
        ui_main_menu_render();

        int input = get_user_input();
        if (input != 0) {
            ui_main_menu_handle_input(input);
        }

        // Optional: kleine Pause einbauen, damit das Menü nicht flackert
        // z. B. sleep(0.1) oder delay_ms(100), je nach Plattform
    }

    return 0;
}
