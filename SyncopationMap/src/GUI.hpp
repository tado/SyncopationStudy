#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class GUI {
public:
    GUI();
    void update();
    void draw();
    
    ofxPanel gui;
    ofxToggle drawSynco;
};
