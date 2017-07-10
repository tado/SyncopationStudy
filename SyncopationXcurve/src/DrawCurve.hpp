#pragma once
#include "ofMain.h"

class DrawCurve {
public:
    DrawCurve();
    void update();
    void draw();

    static const int num = 9;
    vector<float> mouseWeight;
};
