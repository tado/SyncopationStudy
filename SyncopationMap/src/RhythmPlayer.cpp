#include "RhythmPlayer.hpp"
#include "ofApp.h"

RhythmPlayer::RhythmPlayer(): count(0), shouldThrowTestException(false){
    bpm = 120;
    cp.load("HANDCLP0.wav");
    bd.load("BT0A0A7.wav");
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

            string beat = app->rhythmPicker->pickedBit[0];
            if (beat.at(count) == '1') {
                cp.play();
            }
            count = (count+1) % 8;
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
