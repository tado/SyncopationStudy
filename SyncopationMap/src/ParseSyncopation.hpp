//
//  ParseSyncopation.hpp
//  SyncopationMap
//
//  Created by Atsushi Tadokoro on 2017/05/03.
//
//

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
    ofVec2f location;
    ofVec2f screenLocation;
};

class ParseSyncopation {

public:
    ParseSyncopation(string filename);
    void draw();
    
    ofxJSONElement result;
    vector<Bar> bar;
    float drawMargin;
    float syncopationMax, syncopationMin;
    float radius;
};

