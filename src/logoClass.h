//
//  logoClass.hpp
//  logoAnimation
//
//  Created by Jasper on 15/5/19.
//

//#ifndef logoClass_hpp
//#define logoClass_hpp

//#include <stdio.h>

//#endif /* logoClass_hpp */


#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
//#include "ofxPoco.h"

class logoClass : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void drawRotate();
  //  void drawZoom();
    
	void oscillateX();
	void oscillateY();
	void jitter();

	void setOscX(bool X);
	void setOscY(bool Y);
	void setJitter(bool J);

	void setRotate(bool rot);
    void setSpeed(float sp);
    void setScale(int sc, int sv);
    void setColor(int r, int g, int b);
    void setCoefficient(float co);
    
  //  void setArms(int arms);
	void startTimer();
	void updateTimer();

    ofxSVG logo;
    float step;
    vector<ofPolyline> outlines;
    
    float speed;
    int scale;
    bool rotate;
	bool oscX;
	bool oscY;
	bool jit;

    float coefficient;
    
	int prevTime;
	int curTime;
	bool timedOut;
	int timeOut;

    int red;
    int green;
    int blue;

	float wave;
	float waveMap;

    
};
