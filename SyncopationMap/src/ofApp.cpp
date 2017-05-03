#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(30);
    bool parsingSuccessfulSG = resultSG.open("SG.json");
    if (parsingSuccessfulSG){
        for (int i = 0; i < 256; i++) {
            Bar b;
            b.num = i;
            b.syncopation = resultSG["syncopation_by_bar"][i].asFloat();
            bitset<8> value(i);
            string bitStr = value.to_string<char,std::string::traits_type,std::string::allocator_type>();
            b.bit = bitStr;
            int noteNum = 0;
            for (int i = 0; i < bitStr.length(); i++) {
                if (bitStr.at(i) == '1') {
                    noteNum++;
                }
            }
            b.noteNum = noteNum;
            barSG.push_back(b);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 127, 31, 127);
    for (int i = 0; i < 256; i++) {
        float x = ofMap(barSG[i].syncopation, 0.0, 2.0, 100, ofGetWidth()-100);
        float y = ofMap(barSG[i].noteNum, 0, 8, ofGetHeight()-100, 100);
        ofDrawCircle(x, y, 12);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
