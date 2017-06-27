#include "Recorder.hpp"
#include "ofApp.h"

Recorder::Recorder(){
    started = false;
    time_t current = time(0);
    filename = "./record/" + ofToString(current) + ".xml";
    xml.saveFile(filename);
    xml.clear();
    int tagNum = xml.addTag("record");
    xml.setValue("record:unixtime", int(current), tagNum);
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
        xml.setValue("pt:frameNum", int(ofGetFrameNum()), tagNum);
        xml.setValue("pt:x", app->mouseX, tagNum);
        xml.setValue("pt:y", app->mouseY, tagNum);
    }
}

void Recorder::draw(){
    if (started == false) {
        ofSetColor(0);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
}

void Recorder::exit(){
    xml.saveFile(filename);
    cout << "settings saved to xml!" << endl;
}
