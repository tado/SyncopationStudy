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
    int loopCount;
    float bpm;
    Poco::AtomicCounter shouldThrowTestException;
    ofSoundPlayer cp;
    ofSoundPlayer bd;
    ofSoundPlayer bd2;
    ofSoundPlayer sd;
    ofSoundPlayer highClick;
    ofSoundPlayer lowClick;
    
    string playingBeat;
};
