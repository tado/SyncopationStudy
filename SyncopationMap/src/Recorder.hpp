#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"

class Recorder {
public:
    Recorder();
    void update();
    void exit();
    
    ofxXmlSettings xml;
};
