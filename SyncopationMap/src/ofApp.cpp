#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    
    gui = new GUI();
    showGui = true;
    
    parseSyncoKTH = new ParseSyncopation("KTH.json");
    parseSyncoLHL = new ParseSyncopation("LHL.json");
    parseSyncoPRS = new ParseSyncopation("PRS.json");
    parseSyncoSG = new ParseSyncopation("SG.json");
    parseSyncoTMC = new ParseSyncopation("TMC.json");
    parseSyncoTOB = new ParseSyncopation("TOB.json");
    parseSyncoWNBD  = new ParseSyncopation("WNBD.json");

    recorder = new Recorder();
    rhythmPicker = new RhythmPicker();
    rhythmPlayer = new RhythmPlayer();
    rhythmPlayer->bpm = 120;
    rhythmPlayer->start();
}

//--------------------------------------------------------------
void ofApp::update(){
    switch (gui->syncoMode) {
        case 0:
            parseSynco = parseSyncoKTH;
            break;
        case 1:
            parseSynco = parseSyncoLHL;
            break;
        case 2:
            parseSynco = parseSyncoPRS;
            break;
        case 3:
            parseSynco = parseSyncoSG;
            break;
        case 4:
            parseSynco = parseSyncoTMC;
            break;
        case 5:
            parseSynco = parseSyncoTOB;
            break;
        case 6:
            parseSynco = parseSyncoWNBD;
            break;
        default:
            break;
    }
    
    rhythmPicker->update();
    gui->update();
    recorder->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (gui->drawSynco) {
        parseSynco->draw();
        rhythmPlayer->draw();
    }
    
    rhythmPicker->draw();

    if (showGui) {
        gui->draw();
    }
}

void ofApp::exit(){
    rhythmPlayer->stop();
    recorder->exit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'g') {
        if (showGui) {
            showGui = false;
        } else {
            showGui = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    rhythmPicker->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    rhythmPicker->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    rhythmPicker->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    rhythmPicker->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
