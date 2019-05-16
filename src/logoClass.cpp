//
//  logoClass.cpp
//  logoAnimation
//
//  Created by Jasper on 15/5/19.
//

#include "logoClass.h"

//--------------------------------------------------------------
void logoClass::setup(){
    
    ofSetVerticalSync(true);
    
    ofBackground(255,0,0);
    
    
    speed = 1;
    scale = 1;
    
    
    ofSetColor(255);
    
    logo.load("logo.svg");
    for (ofPath p: logo.getPaths()){
        // svg defaults to non zero winding which doesn't look so good as contours
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        const vector<ofPolyline>& lines = p.getOutline();
        for(const ofPolyline & line: lines){
            outlines.push_back(line.getResampledBySpacing(1));
        }
    }

	timeOut = 3000;
	timedOut = false;

	 rotate = false;
	 oscX = false;
	 oscY = false;
	 jit = false;
}

//--------------------------------------------------------------
void logoClass::update(){

	wave = sin(ofGetFrameNum()*0.01*speed);

	//waveMap = ofMap(-1, 1, 0, 1);

	
}

//--------------------------------------------------------------
void logoClass::draw(){
    
    
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()),20,20);

    
	updateTimer();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    if (rotate == true){
        drawRotate();
    }
    ofScale(.5,.5);
    ofScale(scale, scale);
    ofTranslate(-logo.getWidth()/2, -logo.getHeight()/2);
	
	if (oscX == true) {
		oscillateX();
	}
	
	if (oscY == true) {
		oscillateY();
	}

	if (jit == true) {
		jitter();
	}

    ofPushStyle();
    ofSetColor(red, green, blue);
    //ofNoFill();
    for (ofPolyline & line: outlines){
        int num = line.size();
        
        ofBeginShape();
        for (int j = 0; j < num; j++){
            ofVertex(line[j]);
        }
        ofEndShape();
    }
    ofPopStyle();
    ofPopMatrix();
    
    
    //speed
    
}


//---------------------------------------------------------
void logoClass::drawRotate(){
    
    ofRotateDeg(speed*ofGetFrameNum());
    
}

void logoClass::startTimer() {

	prevTime = curTime = ofGetElapsedTimeMillis();

}

void logoClass::updateTimer() {

	curTime = ofGetElapsedTimeMillis();
	if ((curTime - prevTime) > timeOut)
	{
		//cout << "TIME!" + ofToString(ofRandom(0, 10))<<endl;
		timedOut = true;
		startTimer();
	}
}

//---------------------------------------------------------
void logoClass::setSpeed(float sp){
    speed = sp;
}

//---------------------------------------------------------
void logoClass::setScale(int sc, int sv){
    scale = sc + sv;
}

//---------------------------------------------------------
void logoClass::setRotate(bool rot){
    rotate = rot;
}

void logoClass::setOscX(bool X) {
	oscX = X;
}
void logoClass::setOscY(bool Y) {
	oscY = Y;
}

void logoClass::setJitter(bool J) {
	jit = J;
}

//---------------------------------------------------------
void logoClass::setCoefficient(float co){
    coefficient = co;
}

//---------------------------------------------------------
void logoClass::setColor(int r, int g, int b){
    red = r;
    green = g;
    blue = b;
}

void logoClass::oscillateX() {
	ofTranslate(wave*coefficient, 0);
}
void logoClass::oscillateY() {
	ofTranslate(0, wave*coefficient);
}

void logoClass::jitter() {
	ofTranslate(ofRandom(0,coefficient), ofRandom(0, coefficient));
}