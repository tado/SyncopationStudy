#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class GUI {
public:
    GUI();
    void update();
    void draw();
    
    ofxPanel gui;
    ofxIntSlider syncoMode;
    ofxIntSlider fps;
    ofxIntSlider expLength;
    ofxToggle drawSynco;
    ofxToggle guideBeat;
    ofxToggle timbre;
};
