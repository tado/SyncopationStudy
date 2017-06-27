#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include <time.h>

class Recorder {
public:
    Recorder();
    void start();
    void stop();
    void update();
    void draw();
    void exit();
    
    ofxXmlSettings xml;
    string filename;
    bool started;
    float startTime;
    ofTrueTypeFont font;
};
