#include "Recorder.hpp"
#include "ofApp.h"

Recorder::Recorder(){
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
        xml.setValue("pt:playingBeat", app->rhythmPlayer->playingBeat, tagNum);
        xml.setValue("pt:x", app->mouseX, tagNum);
        xml.setValue("pt:y", app->mouseY, tagNum);
    }
}

void Recorder::draw(){
    if (started == false) {
        ofSetColor(0);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofDrawBitmapStringHighlight("Push [Space] key when you are ready to proceed.", ofGetWidth()/2 - 200, ofGetHeight()/2-5);
    }
}

void Recorder::exit(){
    xml.saveFile(filename);
    cout << "settings saved to xml!" << endl;
}
