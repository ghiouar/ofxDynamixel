#pragma once

#include "ofMain.h"
#include "ofxGui/src/ofxGui.h"
#include "ofxDynamixel/src/ofConnexion.h"
#include "ofxDynamixel/src/ofControlTable.h"
#include "ofDynamixelServo.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


private:
	ofDynamixelServo * dyna_1;
	ofDynamixelServo * dyna_2;
	ofDynamixelServo * dyna_3;
	ofDynamixelServo * dyna_4;

	void setGUI5();
	void setGUI1();
	void guiEvent(ofxUIEventArgs &e);


	ofxUISuperCanvas *gui5;
	ofxUISuperCanvas *gui1;

	ofxUIDropDownList* ids;
	ofxUIRotarySlider * rotation;
	int id;
};
