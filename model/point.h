#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

class Point {
private:
    float x, y;

public:
    Point(float x, float y);
};

#endif