#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    
    //parseSynco = new ParseSyncopation("LHL.json");
    //parseSynco = new ParseSyncopation("SG.json");
    //parseSynco = new ParseSyncopation("KTH.json");
    parseSynco = new ParseSyncopation("PRS.json");
    //parseSynco = new ParseSyncopation("TMC.json");
    //parseSynco = new ParseSyncopation("TOB.json");
    //parseSynco = new ParseSyncopation("WNBD.json");
    
    rhythmPicker = new RhythmPicker();
    
    rhythmPlayer = new RhythmPlayer();
    rhythmPlayer->start();
}

//--------------------------------------------------------------
void ofApp::update(){
    rhythmPicker->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 100);
    parseSynco->draw();
    rhythmPicker->draw();
    rhythmPlayer->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
