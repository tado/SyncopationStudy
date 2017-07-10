//
//  DrawFitting.cpp
//  SyncopationXcurve
//
//  Created by Atsushi Tadokoro on 2017/07/10.
//
//

#include "DrawFitting.hpp"
#include "ofApp.h"

DrawFitting::DrawFitting(){
    for (int i = 0; i < num; i++) {
        in[i] = 0.0;
        out[i] = 0.0;
    }
    dim = 4;
    init(num, dim);
    started = false;
}

void DrawFitting::update(){
    if (started) {
        ofApp *app = ((ofApp*)ofGetAppPtr());
        double m;
        int d = dim;
        
        in[int(app->mouseX)]++;
        
        for (int i = 0; i < d; i++){
            m = prod(in, w[i], num);
            for (int j = 0; j < num; j++) {
                out[j] += m * w[i][j];
            }
        }
    }
}

void DrawFitting::draw(){
    if (started) {
        float min = 100000;
        float max = -100000;
        
        for (int i = 0; i < num; i++){
            if (out[i] < min) {
                min = out[i];
            }
            if (out[i] > max) {
                max = out[i];
            }
        }
        
        ofSetColor(172);
        ofNoFill();
        ofBeginShape();
        for (int i = 0; i < num; i++) {
            float x = ofMap(i, 0, num, 0, ofGetWidth());
            float y = ofMap(out[i], min, max, ofGetHeight()/2 + ofGetHeight()/4, ofGetHeight()/2 - ofGetHeight()/4);
            ofVertex(x, y);
        }
        ofEndShape();
        ofFill();
        /*
        for (int i = 0; i < num; i++) {
            float x = ofMap(i, 0, num, 0, ofGetWidth());
            float y = ofMap(in[i], 0, 1000, ofGetHeight()/2 + ofGetHeight()/3, ofGetHeight()/2 - ofGetHeight()/3);
            ofDrawCircle(x, y, 2);
        }
        */
    }
}

double DrawFitting::prod(double a[], double b[], int n){
    double ret = 0.0;
    int i;
    for (i = 0; i < n; i++)
        ret += a[i] * b[i];
    return ret;
}

void DrawFitting::init(int n, int d){
    int d1, d2, i;
    double m;
    
    // generate x^0, x^1
    for (i = 0; i < n; i++){
        w[0][i] = 1.0;
        w[1][i] = 2.0 *  i / (n - 1.0) - 1.0;
    }
    
    // generate x^i
    for (d1 = 2; d1 < d; d1++)
        for (i = 0; i < n; i++)
            w[d1][i] = w[d1 - 1][i] * w[1][i];
    
    // Gram-Schmidt algorithm
    for (d1 = 0; d1 < d; d1++)
    {
        for (d2 = 0; d2 < d1; d2++)
        {
            m = prod(w[d1], w[d2], n);
            for (i = 0; i < n; i++)
                w[d1][i] -= m * w[d2][i];
        }
        
        m = sqrt(prod(w[d1], w[d1], n));
        for (i = 0; i < n; i++)
            w[d1][i] /= m;
    }
}
