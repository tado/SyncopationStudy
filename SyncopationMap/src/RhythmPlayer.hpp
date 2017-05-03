#pragma once
#include "ofThread.h"
#include "ofMain.h"

class RhythmPlayer: public ofThread {
public:
    RhythmPlayer();
    void start();
    void stop();
    void threadedFunction();
    void draw();
    //int getCount();
    //void throwTestException();
    
    int count;
    float bpm;
    Poco::AtomicCounter shouldThrowTestException;
};
