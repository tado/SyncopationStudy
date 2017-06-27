#include "Recorder.hpp"
#include "ofApp.h"

Recorder::Recorder(){
    xml.saveFile("mySettings.xml");
    xml.clear();
}

void Recorder::update(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    int tagNum = xml.addTag("pt");
    xml.setValue("pt:count", tagNum, tagNum);
    xml.setValue("pt:elapsedTimef", ofGetElapsedTimef(), tagNum);
    xml.setValue("pt:frameNum", int(ofGetFrameNum()), tagNum);
    xml.setValue("pt:x", app->mouseX, tagNum);
    xml.setValue("pt:y", app->mouseY, tagNum);
}

void Recorder::exit(){
    xml.saveFile("mySettings.xml");
    cout << "settings saved to xml!" << endl;
}
