#pragma once
#include "ofMain.h"

class DrawFitting {
public:
    DrawFitting();
    double prod(double a[], double b[], int n);
    void init(int n, int d);
    void update();
    void draw();
    
    static const int num = 1440;
    double w[32][num];
    double in[num];
    double out[num];
    int dim;
    bool started;
};
