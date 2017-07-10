#pragma once
#include "ofMain.h"

class DrawCurve {
public:
    DrawCurve();
    void update();
    void draw();
    //double *least(int m, int n, double *x, double *y);
    //int gauss(double **w, int n, int m, double eps);

    static const int num = 9;
    vector<float> mouseWeight;
};
