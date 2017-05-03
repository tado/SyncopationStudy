#include "RhythmPicker.hpp"
#include "ofApp.h"

RhythmPicker::RhythmPicker(){
    rhythmDist = 10000;
    pickedRhythm.clear();
    pickedBit.clear();
}

void RhythmPicker::update(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    for (int i = 0; i < app->parseSynco->bar.size(); i++) {
        float dist = mouseLoc.distance(app->parseSynco->bar[i].screenLocation);
        if (dist < rhythmDist) {
            rhythmDist = dist;
        }
    }
    pickedRhythm.clear();
    pickedBit.clear();
    for (int i = 0; i < app->parseSynco->bar.size(); i++) {
        float dist = mouseLoc.distance(app->parseSynco->bar[i].screenLocation);
        if (dist == rhythmDist) {
            pickedRhythm.push_back(i);
            pickedBit.push_back(app->parseSynco->bar[i].bit);
        }
    }
}

void RhythmPicker::draw(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    
    ofSetColor(255, 127);
    ofDrawLine(mouseLoc.x, 0, mouseLoc.x, ofGetHeight());
    ofDrawLine(0, mouseLoc.y, ofGetWidth(), mouseLoc.y);
    
    ofVec2f pickedLoc;
    pickedLoc = app->parseSynco->bar[pickedRhythm[0]].screenLocation;
    ofSetColor(255, 0, 0, 127);
    ofDrawCircle(pickedLoc, 10);
    
    ofSetColor(255);
    for (int i = 0; i < pickedRhythm.size(); i++) {
        string bitStr = app->parseSynco->bar[pickedRhythm[i]].bit;
        ofDrawBitmapString(bitStr, 20, 20 + i * 15);
    }
}

void RhythmPicker::mouseMoved(int x, int y){
    rhythmDist = 10000;
    pickedRhythm.clear();
    mouseLoc.x = x;
    mouseLoc.y = y;
}
