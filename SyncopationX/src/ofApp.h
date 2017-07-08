#pragma once

#include "ofMain.h"
#include "ParseSyncopation.hpp"
#include "RhythmPicker.hpp"
#include "RhythmPlayer.hpp"
#include "GUI.hpp"
#include "Recorder.hpp"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void exit();
    
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
    
    ParseSyncopation *parseSynco;
    ParseSyncopation *parseSyncoKTH;
    ParseSyncopation *parseSyncoLHL;
    ParseSyncopation *parseSyncoPRS;
    ParseSyncopation *parseSyncoSG;
    ParseSyncopation *parseSyncoTMC;
    ParseSyncopation *parseSyncoTOB;
    ParseSyncopation *parseSyncoWNBD;
    
    RhythmPicker *rhythmPicker;
    RhythmPlayer *rhythmPlayer;
    GUI *gui;
    Recorder *recorder;
    bool showGui;
};
