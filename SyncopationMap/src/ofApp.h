#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include<bitset>

class Bar {
public:
    int num;
    string bit;
    float syncopation;
    int noteNum;
};

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxJSONElement resultSG;
    vector<Bar> barSG;
    //float SG[256];
    //ofxJSONElement resultLHL;
    //float LHL[256];
};
