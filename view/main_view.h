#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <iostream>
#include <math.h>
#include <vector>
#include <controller/main_controller.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#define window_width 640
#define window_height 562.295

class MainView {
    private:
        ALLEGRO_DISPLAY* display;
        MainController mainController;

    public:
        MainView();
        void init();
        void drawTriangle(int level, float offset);
        /////////////////////////////////////////
        ALLEGRO_DISPLAY* getAllegroDisplay();
};

#endif