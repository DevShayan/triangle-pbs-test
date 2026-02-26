#include <iostream>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#define window_width 640
#define window_height 562.295

void drawTriangle(int level, float offset);
int getNoOfTriangles(int level);
int getNoOfIntercepts(int level);
bool exit(ALLEGRO_EVENT event);
void showInfo(float x1, float y1, float x2, float y2, float x3, float y3, int level);

/*
no of triangles = p * 4;
no of intercepts = 2p + 1;
*/

int main() {

    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    if (!al_init_primitives_addon()) {
        fprintf(stderr, "failed to initialize primitives addon!\n");
        return -1;
    }
    if (!al_init_native_dialog_addon()) {
        fprintf(stderr, "failed to initialize dialog addon!\n");
        return -1;
    }
    if (!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize keyboard!\n");
        return -1;
    }

    ALLEGRO_DISPLAY* display = al_create_display(window_width, window_height);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

    ALLEGRO_EVENT event;

    if (!display) {
        al_show_native_message_box(display, "Display Error", "Error:", "Unable to create display!", "OK", ALLEGRO_MESSAGEBOX_WARN);
        return -1;
    }

    int level = 2;
    float offset = 30.0;
    float width = window_width - offset;
    float height = window_height - offset;

    while (!exit(event)) {
        al_wait_for_event(event_queue, &event);
        al_clear_to_color(al_map_rgb(255, 255, 255));
        drawTriangle(level, offset);
        al_flip_display();
        showInfo(
            window_width / 2, offset,
            offset, height,
            width, height,
            level
        );
    }

    al_destroy_display(display);
    return 0;
}


void drawTriangle(int level, float offset) {
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

void showInfo(float x1, float y1, float x2, float y2, float x3, float y3, int level) {
    float distanceL, distanceR, distanceB;

    distanceL = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    distanceR = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    distanceB = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    fprintf(stderr, "No of intercepts: %d", getNoOfIntercepts(level));
    //fprintf(stdout, "Distance L: %f\nDistance R: %f\nDistance B: %f\n", distanceL, distanceR, distanceB);
    //fprintf(stdout, "A(%f, %f)\nB(%f, %f)\nC(%f, %f)\n", x1, y1, x2, y2, x3, y3);
}


int getNoOfTriangles(int level) {
    if (level == 1) {
        return 1;
    }
    return getNoOfTriangles(level - 1) * 4;
}


int getNoOfIntercepts(int level) {
    if (level == 1) {
        return 0;
    }
    return ((getNoOfIntercepts(level - 1) * 2) + 1);
}


bool exit(ALLEGRO_EVENT event) {
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return true;
    }
    return false;
}
