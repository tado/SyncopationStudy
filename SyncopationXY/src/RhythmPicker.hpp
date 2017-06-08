#pragma once
#include "ofMain.h"

class RhythmPicker {
public:
    RhythmPicker();
    void update();
    void draw();
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    bool selected;
    ofVec2f selectLoc;
    float rhythmDistX;
    float rhythmDistY;
    vector<int> pickedRhythmX;
    vector<string> pickedBitX;
    vector<int> pickedRhythmY;
    vector<string> pickedBitY;
};
