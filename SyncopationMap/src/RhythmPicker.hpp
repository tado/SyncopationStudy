#pragma once
#include "ofMain.h"

class RhythmPicker {
public:
    RhythmPicker();
    void update();
    void draw();
    void mouseMoved(int x, int y );
    
    ofVec2f mouseLoc;
    float rhythmDist;
    int pickedRhythm;
};