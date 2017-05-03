#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    
    parseSyncoSG = new ParseSyncopation("SG.json");
    parseSyncoLHL = new ParseSyncopation("LHL.json");
    parseSyncoKTH = new ParseSyncopation("KTH.json");
    parseSyncoPRS = new ParseSyncopation("PRS.json");
    parseSyncoTMC = new ParseSyncopation("TMC.json");
    parseSyncoTOB = new ParseSyncopation("TOB.json");
    parseSyncoWNBD = new ParseSyncopation("WNBD.json");
    
    rhythmPicker = new RhythmPicker();
}

//--------------------------------------------------------------
void ofApp::update(){
    rhythmPicker->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 100);
    //parseSyncoSG->draw();
    //parseSyncoLHL->draw();
    //parseSyncoKTH->draw();
    parseSyncoPRS->draw();
    //parseSyncoTMC->draw();
    //parseSyncoTOB->draw();
    //parseSyncoWNBD->draw();
    
    rhythmPicker->draw();
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
