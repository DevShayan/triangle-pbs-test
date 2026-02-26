#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <iostream>
#include <math.h>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

class MainController {
private:
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* eventQueue;

public:
    MainController();
    void initEventSources(ALLEGRO_DISPLAY* display);
    bool exit();
};

#endif