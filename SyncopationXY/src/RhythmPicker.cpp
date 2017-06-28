#include "RhythmPicker.hpp"
#include "ofApp.h"

RhythmPicker::RhythmPicker(){
    rhythmDistX = 10000;
    rhythmDistY = 10000;
    pickedRhythmX.clear();
    pickedBitX.clear();
    pickedRhythmY.clear();
    pickedBitY.clear();
    selected = false;
    selectLoc.set(40, ofGetHeight() - 40);
}

void RhythmPicker::update(){
    ofApp *app = ((ofApp*)ofGetAppPtr());

    //X
    for (int i = 0; i < app->parseSynco->barX.size(); i++) {
        float dist = selectLoc.distance(app->parseSynco->barX[i].screenLocation);
        if (dist < rhythmDistX) {
            rhythmDistX = dist;
        }
    }
    pickedRhythmX.clear();
    pickedBitX.clear();
    for (int i = 0; i < app->parseSynco->barX.size(); i++) {
        float dist = selectLoc.distance(app->parseSynco->barX[i].screenLocation);
        if (dist == rhythmDistX) {
            pickedRhythmX.push_back(i);
            pickedBitX.push_back(app->parseSynco->barX[i].bit);
        }
    }
    
    //Y
    for (int i = 0; i < app->parseSynco->barY.size(); i++) {
        float dist = selectLoc.distance(app->parseSynco->barY[i].screenLocation);
        if (dist < rhythmDistY) {
            rhythmDistY = dist;
        }
    }
    pickedRhythmY.clear();
    pickedBitY.clear();
    for (int i = 0; i < app->parseSynco->barY.size(); i++) {
        float dist = selectLoc.distance(app->parseSynco->barY[i].screenLocation);
        if (dist == rhythmDistY) {
            pickedRhythmY.push_back(i);
            pickedBitY.push_back(app->parseSynco->barY[i].bit);
        }
    }
}

void RhythmPicker::draw(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    
    ofVec2f pickedLocX;
    ofVec2f pickedLocY;
    pickedLocX = app->parseSynco->barX[pickedRhythmX[0]].screenLocation;
    pickedLocY = app->parseSynco->barY[pickedRhythmY[0]].screenLocation;
    if (app->gui->drawSynco) {
        ofSetColor(255, 0, 0, 127);
        ofDrawCircle(pickedLocX, 10);
        ofDrawCircle(pickedLocY, 10);
        ofSetColor(255);
        for (int i = 0; i < pickedRhythmX.size(); i++) {
            string bitStr;
            bitStr = app->parseSynco->barX[pickedRhythmX[i]].bit;
            ofDrawBitmapString(bitStr, ofGetWidth() - 120, 40 + i * 15);
        }
        for (int i = 0; i < pickedRhythmY.size(); i++) {
            string bitStr;
            bitStr = app->parseSynco->barY[pickedRhythmY[i]].bit;
            ofDrawBitmapString(bitStr, ofGetWidth() - 200, 40 + i * 15);
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
        ofDrawBitmapString("Model: " + slectedMode, ofGetWidth() - 200, 20);
    }
    
    ofSetColor(63, 127, 255);
    ofDrawCircle(selectLoc, 15);
}

void RhythmPicker::mouseMoved(int x, int y){
    rhythmDistX = 10000;
    rhythmDistY = 10000;
    pickedRhythmX.clear();
    pickedRhythmY.clear();
    selectLoc.x = x;
    selectLoc.y = y;
}

/*
void RhythmPicker::mousePressed(int x, int y, int button){
    float dist = selectLoc.distance(ofVec2f(x, y));
    if (dist < 50) {
        selected = true;
    } else {
        selected = false;
    }
}

void RhythmPicker::mouseReleased(int x, int y, int button){
    selected = false;
}

void RhythmPicker::mouseDragged(int x, int y, int button){
    if (selected) {
        rhythmDistX = 10000;
        rhythmDistY = 10000;
        pickedRhythmX.clear();
        pickedRhythmY.clear();
        selectLoc.x = x;
        selectLoc.y = y;
    }
}
*/
