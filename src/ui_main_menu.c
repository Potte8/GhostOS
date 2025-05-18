#include "ui_main_menu.h"
#include "../language.h" // dein Sprachmodul
#include <stdio.h>

static int selected_menu = 0;

void ui_main_menu_init(void) {
    selected_menu = 0;
}

void ui_main_menu_render(void) {
    printf("=== GhostOS Main Menu ===\n\n");
    for (int i = 0; i < MENU_COUNT; i++) {
        if (i == selected_menu) {
            printf("-> ");
        } else {
            printf("   ");
        }
        printf("%s\n", get_translation(menu_labels[i]));
    }
}

void ui_main_menu_handle_input(int button) {
    switch (button) {
        case 1: // Hoch
            selected_menu = (selected_menu - 1 + MENU_COUNT) % MENU_COUNT;
            break;
        case 2: // Runter
            selected_menu = (selected_menu + 1) % MENU_COUNT;
            break;
        case 3: // OK
            switch (selected_menu) {
                case MENU_PENTESTING:
                    // Aufruf Pentesting-App
                    break;
                case MENU_TOOLS:
                    // Aufruf Tools
                    break;
                case MENU_SETTINGS:
                    // Aufruf Settings
                    break;
            }
            break;
    }
}
