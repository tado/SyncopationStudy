#include "RhythmPlayer.hpp"
#include "ofApp.h"

RhythmPlayer::RhythmPlayer():
count(0), loopCount(0), bpm(120), shouldThrowTestException(false) {
    cp.load("HANDCLP0.wav");
    bd.load("BT0A0A7.wav");
    sd.load("ST0T0S7.wav");
}

void RhythmPlayer::start(){
    startThread();
}

void RhythmPlayer::stop(){
    stopThread();
}

void RhythmPlayer::threadedFunction(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    while(isThreadRunning()){
        if(lock()){
            unlock();

            if (count == 0) {
                bd.play();
            }
            if (count == 4) {
                sd.play();
            }

            int pickBitNum = (loopCount/4) % app->rhythmPicker->pickedBit.size();
            string beat = app->rhythmPicker->pickedBit[pickBitNum];
            if (beat.at(count) == '1') {
                cp.play();
            }
            count = (count+1) % 8;
            if (count == 0) {
                loopCount++;
            }
            sleep((120.0/bpm)*1000/8);
        }
    }
}

void RhythmPlayer::draw(){

    if (count == 0) {
        ofSetColor(255);
        ofDrawCircle(ofGetWidth()-40, 40, 5);
    }
}
