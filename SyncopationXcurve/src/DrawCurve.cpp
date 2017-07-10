#include "DrawCurve.hpp"
#include "ofApp.h"

int gauss(double **, int, int, double);
double *least(int, int, double *, double *);

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
        
        ofSetColor(172);
        ofNoFill();
        ofBeginShape();
        float x = ofMap(0, 0, 8, drawMargin, ofGetWidth()-drawMargin);
        float y = ofMap(mouseWeight[0], min, max, ofGetHeight()- (drawMargin*2), drawMargin*2);
        ofCurveVertex(x, y);
        ofCurveVertex(x, y);
        for (int i = 0; i < num; i++) {
            float x = ofMap(i, 0, 8, drawMargin, ofGetWidth()-drawMargin);
            float y = ofMap(mouseWeight[i], min, max, ofGetHeight()- (drawMargin*2), drawMargin*2);
            ofCurveVertex(x, y);
        }
        
        //draw curve
        x = ofMap(8, 0, 8, drawMargin, ofGetWidth()-drawMargin);
        y = ofMap(mouseWeight[8], min, max, ofGetHeight()- (drawMargin*2), drawMargin*2);
        ofCurveVertex(x, y);
        ofCurveVertex(x, y);
        ofEndShape();
        ofFill();
        
        //draw spot
        /*
        ofSetColor(0, 0, 255);
        for (int i = 0; i < num; i++) {
            float x = ofMap(i, 0, 8, drawMargin, ofGetWidth()-drawMargin);
            float y = ofMap(mouseWeight[i], min, max, ofGetHeight()-drawMargin*2, drawMargin*2);
            ofDrawCircle(x, y, 4);
        }
        */
    }
}

double *least(int m, int n, double *x, double *y) {
    double **A, **w, *z, x1, x2;
    int i1, i2, i3, sw;
    
    m++;
    z = new double [m];
    w = new double * [m];
    for (i1 = 0; i1 < m; i1++)
        w[i1] = new double [m+1];
    A = new double * [n];
    
    for (i1 = 0; i1 < n; i1++) {
        A[i1]      = new double [m];
        A[i1][m-2] = x[i1];
        A[i1][m-1] = 1.0;
        x1         = A[i1][m-2];
        x2         = x1;
        for (i2 = m-3; i2 >= 0; i2--) {
            x2        *= x1;
            A[i1][i2]  = x2;
        }
    }
    
    for (i1 = 0; i1 < m; i1++) {
        for (i2 = 0; i2 < m; i2++) {
            w[i1][i2] = 0.0;
            for (i3 = 0; i3 < n; i3++)
                w[i1][i2] += A[i3][i1] * A[i3][i2];
        }
    }
    
    for (i1 = 0; i1 < m; i1++) {
        w[i1][m] = 0.0;
        for (i2 = 0; i2 < n; i2++)
            w[i1][m] += A[i2][i1] * y[i2];
    }
    
    sw = gauss(w, m, 1, 1.0e-10);
    
    if (sw == 0) {
        for (i1 = 0; i1 < m; i1++)
            z[i1] = w[i1][m];
    }
    else
        z = NULL;
    
    for (i1 = 0; i1 < n; i1++)
        delete [] A[i1];
    for (i1 = 0; i1 < m; i1++)
        delete [] w[i1];
    delete [] A;
    delete [] w;
    
    return z;
}

int gauss(double **w, int n, int m, double eps) {
    double y1, y2;
    int ind = 0, nm, m1, m2, i1, i2, i3;
    
    nm = n + m;
    
    for (i1 = 0; i1 < n && ind == 0; i1++) {
        
        y1 = .0;
        m1 = i1 + 1;
        m2 = 0;
        
        for (i2 = i1; i2 < n; i2++) {
            y2 = fabs(w[i2][i1]);
            if (y1 < y2) {
                y1 = y2;
                m2 = i2;
            }
        }
        
        if (y1 < eps)
            ind = 1;
        
        else {
            
            for (i2 = i1; i2 < nm; i2++) {
                y1        = w[i1][i2];
                w[i1][i2] = w[m2][i2];
                w[m2][i2] = y1;
            }
            
            y1 = 1.0 / w[i1][i1];
            
            for (i2 = m1; i2 < nm; i2++)
                w[i1][i2] *= y1;
            
            for (i2 = 0; i2 < n; i2++) {
                if (i2 != i1) {
                    for (i3 = m1; i3 < nm; i3++)
                        w[i2][i3] -= w[i2][i1] * w[i1][i3];
                }
            }
        }
    }
    
    return(ind);
}
