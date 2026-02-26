#include "main_model.h"

MainModel::MainModel() {
    //
}


int MainModel::getNoOfTriangles(int level) {
    if (level == 1) {
        return 1;
    }
    return getNoOfTriangles(level - 1) * 4;
}


int MainModel::getNoOfIntercepts(int level) {
    if (level == 1) {
        return 0;
    }
    return ((getNoOfIntercepts(level - 1) * 2) + 1);
}




