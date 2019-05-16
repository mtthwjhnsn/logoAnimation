#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "logoClass.h"
#include "audioClass.h"
#include "ofxGui.h"
//#include "ofxPoco.h"

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
    
    logoClass logo;
    
    audioClass audio;

    //bool rotate;
    //float speed;
    //float scale;
    
    //GUI
    
    ofxPanel gui;

    
    ofxFloatSlider red;
    ofxFloatSlider green;
    ofxFloatSlider blue;
    
    ofxToggle rotate;
	ofxToggle soundActivation;

	ofxToggle jitter;

	ofxToggle oscX;
	ofxToggle oscY;
	//ofxToggle soundActivation;

    ofxFloatSlider speed;
    ofxFloatSlider scale;
	ofxInputField<float> coefficient;
	float coef;

    
};
