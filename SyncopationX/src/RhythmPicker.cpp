#include "RhythmPicker.hpp"
#include "ofApp.h"

RhythmPicker::RhythmPicker(){
    rhythmDist = 10000;
    pickedRhythm.clear();
    pickedBit.clear();
    selected = false;
    selectLoc.set(40, ofGetHeight() - 40);
}

void RhythmPicker::update(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    for (int i = 0; i < app->parseSynco->bar.size(); i++) {
        float dist = selectLoc.distance(app->parseSynco->bar[i].screenLocation);
        if (dist < rhythmDist) {
            rhythmDist = dist;
        }
    }
    pickedRhythm.clear();
    pickedBit.clear();
    for (int i = 0; i < app->parseSynco->bar.size(); i++) {
        float dist = selectLoc.distance(app->parseSynco->bar[i].screenLocation);
        if (dist == rhythmDist) {
            pickedRhythm.push_back(i);
            pickedBit.push_back(app->parseSynco->bar[i].bit);
        }
    }
}

void RhythmPicker::draw(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    
    ofVec2f pickedLoc;
    pickedLoc = app->parseSynco->bar[pickedRhythm[0]].screenLocation;

    if (app->gui->drawSynco) {
        ofSetColor(255, 0, 0, 127);
        ofDrawCircle(pickedLoc, 10);
        /*
        ofSetColor(255);
        for (int i = 0; i < pickedRhythm.size(); i++) {
            string bitStr = app->parseSynco->bar[pickedRhythm[i]].bit;
            ofDrawBitmapString(bitStr, ofGetWidth() - 120, 40 + i * 15);
        }
        
        string slectedMode;
        switch (app->gui->syncoMode) {
            case 0:
                slectedMode = "KTH";
                break;
            case 1:
                slectedMode = "LHL";
                break;
            case 2:
                slectedMode = "PRS";
                break;
            case 3:
                slectedMode = "SG";
                break;
            case 4:
                slectedMode = "TMC";
                break;
            case 5:
                slectedMode = "TOB";
                break;
            case 6:
                slectedMode = "WNBD";
                break;
            default:
                break;
        }
        ofDrawBitmapString("Model: " + slectedMode, ofGetWidth() - 120, 20);
     */
    }
    /*
    ofSetColor(63, 127, 255);
    ofDrawCircle(selectLoc, 15);
    */
}

void RhythmPicker::mouseMoved(int x, int y){
    rhythmDist = 10000;
    pickedRhythm.clear();
    selectLoc.x = x;
    selectLoc.y = y;
}

void RhythmPicker::mousePressed(int x, int y, int button){
    /*
    float dist = selectLoc.distance(ofVec2f(x, y));
    if (dist < 50) {
        selected = true;
    } else {
        selected = false;
    }
    */
}

void RhythmPicker::mouseReleased(int x, int y, int button){
    //selected = false;
}

void RhythmPicker::mouseDragged(int x, int y, int button){
    /*
    if (selected) {
        rhythmDist = 10000;
        pickedRhythm.clear();
        selectLoc.x = x;
        selectLoc.y = y;
    }
    */
}
