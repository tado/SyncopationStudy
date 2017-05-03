#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    
    gui = new GUI();
    showGui = false;
    
    //parseSynco = new ParseSyncopation("LHL.json");
    //parseSynco = new ParseSyncopation("SG.json");
    //parseSynco = new ParseSyncopation("KTH.json");
    parseSynco = new ParseSyncopation("PRS.json");
    //parseSynco = new ParseSyncopation("TMC.json");
    //parseSynco = new ParseSyncopation("TOB.json");
    //parseSynco = new ParseSyncopation("WNBD.json");
    
    rhythmPicker = new RhythmPicker();
    rhythmPlayer = new RhythmPlayer();
    rhythmPlayer->bpm = 120;
    rhythmPlayer->start();
}

//--------------------------------------------------------------
void ofApp::update(){
    rhythmPicker->update();
    gui->update();
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
