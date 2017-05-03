#include "RhythmPicker.hpp"
#include "ofApp.h"

RhythmPicker::RhythmPicker(){
    rhythmDist = 10000;
    pickedRhythm = 0;
}

void RhythmPicker::update(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    for (int i = 0; i < app->parseSyncoPRS->bar.size(); i++) {
        float dist = mouseLoc.distance(app->parseSyncoPRS->bar[i].screenLocation);
        if (dist < rhythmDist) {
            rhythmDist = dist;
            pickedRhythm = i;
        }
    }
}

void RhythmPicker::draw(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    
    ofSetColor(255, 127);
    ofDrawLine(mouseLoc.x, 0, mouseLoc.x, ofGetHeight());
    ofDrawLine(0, mouseLoc.y, ofGetWidth(), mouseLoc.y);
    
    ofVec2f pickedLoc;
    pickedLoc = app->parseSyncoPRS->bar[pickedRhythm].screenLocation;
    ofSetColor(255, 0, 0, 127);
    ofDrawCircle(pickedLoc, 10);
    
    ofSetColor(255);
    string bitStr = app->parseSyncoPRS->bar[pickedRhythm].bit;
    ofDrawBitmapString(bitStr, 20, 20);
}

void RhythmPicker::mouseMoved(int x, int y){
    rhythmDist = 10000;
    mouseLoc.x = x;
    mouseLoc.y = y;
}
