//
//  audioClass.hpp
//  logoAnimation
//
//  Created by Jasper on 15/5/19.
//

#pragma once

#include "ofMain.h"

class audioClass : public ofBaseApp{

    public:
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void audioIn(ofSoundBuffer & input);
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int     bufferCounter;
    int     drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;

};

