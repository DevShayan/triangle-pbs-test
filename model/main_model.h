#ifndef MAIN_MODEL_H
#define MAIN_MODEL_H

#include <iostream>
#include <math.h>
#include <vector>
#include <point.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

class MainModel {
private:
    float window_width, window_height, offset, triWidth, triHeight;
    int level;
    std::vector<Point> interceptsL, interceptsR, interceptsB;

public:
    MainModel();
    int getNoOfTriangles(int level);
    int getNoOfIntercepts(int level);
};

#endif
