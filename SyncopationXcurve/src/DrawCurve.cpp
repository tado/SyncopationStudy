#include "DrawCurve.hpp"
#include "ofApp.h"

DrawCurve::DrawCurve(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    for (int i = 0; i < num; i++) {
        mouseWeight.push_back(0);
    }
}

void DrawCurve::update(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    if (app->recorder->started) {
        float drawMargin = app->parseSynco->drawMargin;
        int n = ofMap(app->mouseX, drawMargin, ofGetWidth()-drawMargin, 0, 8);
        mouseWeight[n]++;
    }
}

void DrawCurve::draw(){
    ofApp *app = ((ofApp*)ofGetAppPtr());
    if (app->recorder->started) {
        float drawMargin = app->parseSynco->drawMargin;
        
        float min = *min_element(mouseWeight.begin(), mouseWeight.end());
        float max = *max_element(mouseWeight.begin(), mouseWeight.end());
        
        ofSetColor(255);
        ofNoFill();
        ofBeginShape();
        float x = ofMap(0, 0, 8, drawMargin, ofGetWidth()-drawMargin);
        float y = ofMap(mouseWeight[0], min, max, ofGetHeight()-drawMargin, drawMargin);
        ofCurveVertex(x, y);
        ofCurveVertex(x, y);
        for (int i = 0; i < num; i++) {
            float x = ofMap(i, 0, 8, drawMargin, ofGetWidth()-drawMargin);
            float y = ofMap(mouseWeight[i], min, max, ofGetHeight()-drawMargin, drawMargin);
            ofCurveVertex(x, y);
        }
        x = ofMap(8, 0, 8, drawMargin, ofGetWidth()-drawMargin);
        y = ofMap(mouseWeight[8], min, max, ofGetHeight()-drawMargin, drawMargin);
        ofCurveVertex(x, y);
        ofCurveVertex(x, y);
        ofEndShape();
        ofFill();
        ofSetColor(0, 0, 255);
        for (int i = 0; i < num; i++) {
            float x = ofMap(i, 0, 8, drawMargin, ofGetWidth()-drawMargin);
            float y = ofMap(mouseWeight[i], min, max, ofGetHeight()-drawMargin, drawMargin);
            ofDrawCircle(x, y, 4);
        }
    }
}
