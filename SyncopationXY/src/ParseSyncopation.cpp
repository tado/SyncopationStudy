#include "ParseSyncopation.hpp"

ParseSyncopation::ParseSyncopation(string filename){
    syncopationMax = -10000;
    syncopationMin = 10000;
    drawMargin = 100;
    radius = 5;

    bool parsingSuccessful = result.open(filename);
    if (parsingSuccessful){
        for (int i = 0; i < 256; i++) {
            Bar b;
            //set num
            b.num = i;
            b.syncopation = result["syncopation_by_bar"][i].asFloat();
            
            //calc min and max
            if (b.syncopation < syncopationMin) {
                syncopationMin = b.syncopation;
            }
            if (b.syncopation > syncopationMax) {
                syncopationMax = b.syncopation;
            }
            
            //set noteNum
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
            
            /*
            //set entropy
            uint vector[8];
            for (int i = 0; i < 8; i++) {
                if (bitStr.at(i) == '1') {
                    vector[i] = 1;
                } else {
                    vector[i] = 0;
                }
            }
            float entropy = calcEntropy(vector, 8);
            b.entropy = entropy;
            */
            
            //push_back into vector
            barX.push_back(b);
            barY.push_back(b);
        }

        //set location
        for (int i = 0; i < barX.size(); i++) {
            Bar b;
            ofVec2f loc;
            ofVec2f screenLoc;
            
            loc.x = ofMap(barX[i].syncopation, syncopationMin, syncopationMax, 0.0, 1.0);
            loc.y = 0.5;
            barX[i].location = loc;
            screenLoc.x = ofMap(barX[i].location.x, 0.0, 1.0, drawMargin, ofGetWidth()-drawMargin);
            screenLoc.y = ofMap(barX[i].location.y, 0.0, 1.0, ofGetHeight()-drawMargin, drawMargin);
            barX[i].screenLocation = screenLoc;

            loc.x = 0.5;
            loc.y = ofMap(barY[i].syncopation, syncopationMin, syncopationMax, 0.0, 1.0);
            barY[i].location = loc;
            screenLoc.x = ofMap(barY[i].location.x, 0.0, 1.0, drawMargin, ofGetWidth()-drawMargin);
            screenLoc.y = ofMap(barY[i].location.y, 0.0, 1.0, ofGetHeight()-drawMargin, drawMargin);
            barY[i].screenLocation = screenLoc;
        }
    }
}

void ParseSyncopation::draw(){
    ofSetColor(255, 100);
    for (int i = 0; i < 256; i++) {
        ofDrawCircle(barX[i].screenLocation, radius);
        ofDrawCircle(barY[i].screenLocation, radius);
    }
}
