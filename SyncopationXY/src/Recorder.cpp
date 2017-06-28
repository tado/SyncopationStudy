#include "Recorder.hpp"
#include "ofApp.h"

Recorder::Recorder(){
    font.load("dinbold.ttf", 22);
    started = false;
    time_t current = time(0);
    filename = ofToDataPath("../record/") + ofToString(current) + ".xml";
    xml.saveFile(filename);
    xml.clear();
    int tagNum = xml.addTag("head");
    xml.setValue("head:unixtime", int(current), tagNum);
}

void Recorder::start(){
    started = true;
    startTime = ofGetElapsedTimef();
}

void Recorder::stop(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    app->rhythmPlayer->stop();
    xml.saveFile(filename);
    started = false;
    startTime = 0;
}

void Recorder::update(){
    if (started) {
        ofApp *app = ((ofApp*)ofGetAppPtr());
        int tagNum = xml.addTag("pt");
        xml.setValue("pt:count", tagNum, tagNum);
        xml.setValue("pt:elapsedTimef", ofGetElapsedTimef() - startTime, tagNum);
        //xml.setValue("pt:frameNum", int(ofGetFrameNum()), tagNum);
        xml.setValue("pt:playingBeatX", app->rhythmPlayer->playingBeatX, tagNum);
        xml.setValue("pt:playingBeatY", app->rhythmPlayer->playingBeatY, tagNum);
        xml.setValue("pt:x", app->mouseX, tagNum);
        xml.setValue("pt:y", app->mouseY, tagNum);
        
        if (ofGetElapsedTimef() - startTime > app->gui->expLength) {
            stop();
        }
    }
}

void Recorder::draw(){
    if (started == false) {
        ofSetColor(0);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(255);
        font.drawString("Push [Space] key when you are ready to proceed.", ofGetWidth()/2 - 300, ofGetHeight()/2-5);
    }
}

void Recorder::exit(){
    xml.saveFile(filename);
    cout << "settings saved to xml!" << endl;
}
