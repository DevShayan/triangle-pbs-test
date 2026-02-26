#include "main_view.h"

MainView::MainView() {
    MainController mainController = MainController();
}

void MainView::init() {
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        exit(0);
    }
    if (!al_init_primitives_addon()) {
        fprintf(stderr, "failed to initialize primitives addon!\n");
        exit(0);
    }
    if (!al_init_native_dialog_addon()) {
        fprintf(stderr, "failed to initialize dialog addon!\n");
        exit(0);
    }
    if (!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize keyboard!\n");
        exit(0);
    }

    display = al_create_display(window_width, window_height);
    if (!display) {
        fprintf(stderr, "failed to initialize window!\n");
        exit(0);
    }

    mainController.initEventSources(display);
}

void MainView::drawTriangle(int level, float offset) {
    float width = window_width - offset;
    float height = window_height - offset;

    al_draw_triangle(
        window_width / 2, offset,
        offset, height,
        width, height,
        al_map_rgb(0, 0, 0),
        3
    );
}

ALLEGRO_DISPLAY* MainView::getAllegroDisplay() {
    return display;
}




