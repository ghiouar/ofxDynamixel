#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	printf("ofConnexion * portConnexion = new ofConnexion(COM4, 1.0, 57142);\n");
	ofConnexion * portConnexion = new ofConnexion("COM4", 1.0, 57142);

	bool succesConnexion = portConnexion->open();
	//succesConnexion = portConnexion->open();
	printf("bool succesConnexion = portConnexion->open();\n");
	if (succesConnexion)
	{
		printf("Succeeded to open the port!\n");
	}
	else
	{
		printf("Failed to open the port!\n");
		printf("Press any key to terminate...\n");
	}

	succesConnexion = portConnexion->setBaudRate(57142);
	printf("succesConnexion = portConnexion->setBaudRate(57142);\n");
	if (succesConnexion)
	{
		printf("Succeeded to change the baudrate!\n");
	}
	else
	{
		printf("Failed to change the baudrate!\n");
		printf("Press any key to terminate...\n");
	}

		dyna_1 = new ofDynamixelServo(1, portConnexion);
		//dyna_2 = new ofDynamixelServo(2, portConnexion);
		dyna_3 = new ofDynamixelServo(3, portConnexion);
		dyna_4 = new ofDynamixelServo(4, portConnexion);

}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	dyna_1->draw();
	//dyna_2->draw();
	dyna_3->draw();
	dyna_4->draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
