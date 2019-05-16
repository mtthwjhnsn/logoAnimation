#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    
    gui.add(red.setup("red", 0,0,255));
    gui.add(green.setup("green", 0,255,0));
    gui.add(blue.setup("blue", 255,0,255));
    
	gui.add(rotate.setup("rotate", false));
	
	gui.add(jitter.setup("jitter", false));
	gui.add(oscX.setup("oscX", false));

	gui.add(oscY.setup("oscY", false));

	gui.add(soundActivation.setup("soundActivation", false));

    gui.add(speed.setup("speed", 1, -10, 10));
    gui.add(scale.setup("scale", 1, 0, 10));
    
	gui.add(coefficient.setup("coefficent", 1, -100, 100));
    
    ofSetVerticalSync(true);
    
    ofBackground(255,0,0);
    
    logo.setup();
    
 //   rotate = true;
    speed = 1;
	coef = 1;
    scale = 1;
    
    //audio
  //  audio.setup();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    //audio.update();
    
	if (soundActivation == true) {
		coef = /*audio.ScaledVol * */coefficient;
	}
	else {
		coef = coefficient;
	}

    logo.update();

	logo.setJitter(jitter);
	logo.setOscX(oscX);
	logo.setOscY(oscY);
	logo.setCoefficient(coef);
    logo.setRotate(rotate);
    logo.setSpeed(speed);
    logo.setScale(scale,  1);
    logo.setColor(red, green, blue);

   
    
}

//--------------------------------------------------------------
void ofApp::draw(){
       
    logo.draw();
	gui.draw();

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//    audio.keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
