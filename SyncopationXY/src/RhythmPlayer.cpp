#include "RhythmPlayer.hpp"
#include "ofApp.h"

RhythmPlayer::RhythmPlayer():
count(0), loopCount(0), bpm(120), shouldThrowTestException(false) {
    cp.load("HANDCLP0.wav");
    bd.load("BT0A0A7.wav");
    bd2.load("ignorebd.wav");
    sd.load("ST0T0S7.wav");
    hc.load("HHCD2.wav");
    highClick.load("high.wav");
    lowClick.load("low.wav");
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
            
            //generate base beat
            if (app->gui->guideBeat) {
                if (count == 0 || count == 8) {
                    bd.play();
                } else if (count == 4 || count == 12) {
                    bd.play();
                }
            } else {
                if (count == 0) {
                    highClick.play();
                } else if (count % 4 == 0) {
                    lowClick.play();
                }
            }
            
            //generate rhythum X
            if(app->rhythmPicker->pickedBitX.size() > 0){
                int pickBitNum = (loopCount/8) % app->rhythmPicker->pickedBitX.size();
                string beat = app->rhythmPicker->pickedBitX[pickBitNum];
                if (beat.at(count % 8) == '1') {
                    if (app->gui->timbre) {
                        cp.play();
                    } else {
                        sd.play();
                    }
                }
            }
            //generate rhythum Y
            if(app->rhythmPicker->pickedBitY.size() > 0){
                int pickBitNum = (loopCount/8) % app->rhythmPicker->pickedBitY.size();
                string beat = app->rhythmPicker->pickedBitY[pickBitNum];
                if (beat.at(count % 8) == '1') {
                    if (app->gui->timbre) {
                        hc.play();
                    } else {
                        hc.play();
                    }
                }
            }
            
            count = (count+1) % 16;
            if (count == 0) {
                loopCount++;
            }
            
            //sleep 1 beat (bpm/8)
            sleep((120.0/float(app->gui->fps))*1000/8);
        }
    }
}

void RhythmPlayer::draw(){
    /*
     if (count == 0) {
     ofSetColor(255);
     ofDrawCircle(ofGetWidth()-40, 40, 5);
     }
     */
}
