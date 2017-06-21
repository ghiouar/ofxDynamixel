#include "ofApp.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>


//--------------------------------------------------------------
void ofApp::setup() {
		setGUI1();
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	gui1->draw();
	for ( int i = 0; i < taille; i++)
	{
		if (dynamixels[i] != NULL) {
			dynamixels[i]->draw();
		}
	}
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

void ofApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.getName();

	if (name == "1")
	{
		dynamixels[0]->draw();
		dynamixels[0]->show();
		dynamixels[1]->hide();
		dynamixels[2]->hide();
		dynamixels[3]->hide();
		cout << "Dynamixel 1" << endl;
		id = 1;
		rotation->setMin(dynamixels[0]->getMinPosition() / 3.413);
		rotation->setMax(dynamixels[0]->getMaxPosition() / 3.413);
		
	} else if (name == "2")
	{
		dynamixels[0]->hide();
		dynamixels[1]->draw();
		dynamixels[1]->show();
		dynamixels[2]->hide();
		dynamixels[3]->hide();
		cout << "Dynamixel 2" << endl;
		id = 2;
		rotation->setMin(dynamixels[1]->getMinPosition()/ 3.413);
		rotation->setMax(dynamixels[1]->getMaxPosition()/ 3.413);

	} else if (name == "3")
	{
		dynamixels[0]->hide();
		dynamixels[1]->hide();
		dynamixels[2]->draw();
		dynamixels[2]->show();
		dynamixels[3]->hide();
		cout << "Dynamixel 3" << endl;
		id = 3;
		rotation->setMin(dynamixels[2]->getMinPosition() / 3.413);
		rotation->setMax(dynamixels[2]->getMaxPosition() / 3.413);

	} else if (name == "4")
	{
		dynamixels[0]->hide();
		dynamixels[1]->hide();
		dynamixels[2]->hide();
		dynamixels[3]->draw();
		dynamixels[3]->show();
		cout << "Dynamixel 4" << endl;
		id = 4;
		rotation->setMin(dynamixels[3]->getMinPosition() / 3.413);
		rotation->setMax(dynamixels[3]->getMaxPosition() / 3.413);

	}

	if (name == "The angle")
	{
		ofxUIRotarySlider *radio = (ofxUIRotarySlider *)e.widget;
		cout << " Angle: " << radio->getValue() << endl;
		float new_position = radio->getValue();

		switch (id)
		{
		case 1: dynamixels[0]->change(new_position * 3.413);
			/*dynamixels[0]->show()*/;  cout << "1"; break;
		case 2: dynamixels[1]->change(new_position * 3.413);
			/*dynamixels[1]->show()*/; cout << "2"; break;
		case 3: dynamixels[2]->change(new_position * 3.413);
			/*dynamixels[2]->show()*/; cout << "3"; break;
		case 4: dynamixels[3]->change(new_position * 3.413);
			/*dynamixels[3]->show()*/; cout << "4"; break;
		default:
			break;
		}

	}
	if (name == "Move")
	{
		ofxUITextInput * vitesse = (ofxUITextInput *)gui5->getWidget("pos");
		ofxUITextInput * position = (ofxUITextInput *)gui5->getWidget("vit");

		cout << "\nStart Move acceleraztion : " << endl;
		cout << vitesse->getName() << " value: " << vitesse->getTextString() << endl;
		cout << position->getName() << " value: " << position->getTextString() << endl;
		cout << "End Move acceleraztion \n" << endl;

		switch (id)
		{
		case 1: dynamixels[0]->move(std::stoi(vitesse->getTextString()), std::stoi(position->getTextString())); 
			dynamixels[0]->show();  cout << "1"; break;
		case 2: dynamixels[1]->move(std::stoi(vitesse->getTextString()), std::stoi(position->getTextString())); 
			dynamixels[1]->show(); cout << "2"; break;
		case 3: dynamixels[2]->move(std::stoi(vitesse->getTextString()), std::stoi(position->getTextString())); 
			dynamixels[2]->show(); cout << "3"; break;
		case 4: dynamixels[3]->move(std::stoi(vitesse->getTextString()), std::stoi(position->getTextString())); 
			dynamixels[3]->show(); cout << "4"; break;
		default:
			break;
		}
	} 



	if (name == "LED on/off") {
		cout << "LED\n" << led;
		if (cpt < 1) {
			switch (id)
			{
			case 1: setled(0); break;
			case 2: setled(1); break;
			case 3: setled(2); break;
			case 4: setled(3); break;
			default:
				break;
			}
			cpt++;
		}
		else {
			cpt = 0;
		}

	}

	if (name == "Central position") {
		int movingSpeed = 100;
		cout << "Central position";
		switch (id)
		{
		case 1:
			movingSpeed = dynamixels[0]->getDynamixel()->getControlTable()->movingSpeed();
			dynamixels[0]->getDynamixel()->getControlTable()->setMovingSpeed(100);
			dynamixels[0]->getDynamixel()->getControlTable()->setGoalPosition(512);
			dynamixels[0]->getDynamixel()->getControlTable()->setMovingSpeed(movingSpeed); break;
		case 2: 
			movingSpeed = dynamixels[1]->getDynamixel()->getControlTable()->movingSpeed();
			dynamixels[1]->getDynamixel()->getControlTable()->setMovingSpeed(100); 
			cout << "Before Speed " << dynamixels[1]->getDynamixel()->getControlTable()->movingSpeed();
			dynamixels[1]->getDynamixel()->getControlTable()->setGoalPosition(512);
			dynamixels[1]->getDynamixel()->getControlTable()->setMovingSpeed(movingSpeed); 
			cout << "After Speed " << dynamixels[1]->getDynamixel()->getControlTable()->movingSpeed(); 
			break;
		case 3: 
			movingSpeed = dynamixels[2]->getDynamixel()->getControlTable()->movingSpeed();
			dynamixels[2]->getDynamixel()->getControlTable()->setMovingSpeed(100);
			cout << "Before Speed " << dynamixels[1]->getDynamixel()->getControlTable()->movingSpeed();
			dynamixels[2]->getDynamixel()->getControlTable()->setGoalPosition(512); 
			Sleep(1000);
			/*dynamixels[2]->getDynamixel()->getControlTable()->setMovingSpeed(movingSpeed); */
			cout << "After Speed " << dynamixels[1]->getDynamixel()->getControlTable()->movingSpeed();
			break;
		case 4: 
			movingSpeed = dynamixels[3]->getDynamixel()->getControlTable()->movingSpeed();
			dynamixels[3]->getDynamixel()->getControlTable()->setMovingSpeed(100); 
			dynamixels[3]->getDynamixel()->getControlTable()->setGoalPosition(512);
			dynamixels[3]->getDynamixel()->getControlTable()->setMovingSpeed(movingSpeed); break;
		default:
			break;
		}

	}

	if (name == "Scan")
	{

		ofxUITextInput * port = (ofxUITextInput *)gui1->getWidget("Ports");
		ofxUITextInput * baudrates = (ofxUITextInput *)gui1->getWidget("Baudrate");
		ofxUITextInput * id_max = (ofxUITextInput *)gui1->getWidget("id_max");

		
		connect(port->getTextString().c_str(), 1.0, std::stoi(baudrates->getTextString()), std::stoi(id_max->getTextString()));

		//dyna_1 = new ofDynamixelServo(1, portConnexion, 0, 1023);
		//dyna_2 = new ofDynamixelServo(2, portConnexion, 25, 760);
		//dyna_3 = new ofDynamixelServo(3, portConnexion, 170, 845);
		//dyna_4 = new ofDynamixelServo(4, portConnexion, 10, 760);
		if (taille > 0) {
			setGUI2();
			setGUI3();
			setGUI5();
			gui2->draw();
			gui3->draw();
			gui5->draw();

			for (int i = 0; i < taille; i++)
			{
				if (dynamixels[i] != NULL) {
					dynamixels[i]->show();
				}
			}
		}
		
	}


	if (name == "Apply")
	{

		ofxUITextInput * delai = (ofxUITextInput *)gui2->getWidget("delai");
		ofxUITextInput * couple = (ofxUITextInput *)gui2->getWidget("couple");
		ofxUITextInput * angle_min = (ofxUITextInput *)gui2->getWidget("angle_min");
		ofxUITextInput * angle_max = (ofxUITextInput *)gui2->getWidget("angle_max");

		cout << delai->getTextString();

		if (	std::stoi(delai->getTextString()) > 508 || std::stoi(delai->getTextString()) < 0 
				|| std::stoi(couple->getTextString()) < 0 || std::stoi(couple->getTextString()) > 1023 
				|| std::stoi(angle_min->getTextString()) < 0 || std::stoi(angle_min->getTextString()) > 300
				|| std::stoi(angle_max->getTextString()) < 0 || std::stoi(angle_max->getTextString()) > 300
			)
		{
			error->setLabel("Donnée invalide !");
			cout << "Données invalide\n";
		}
		else {
			cout << "Données valide!\n";
			switch (id)
			{
			case 1:
				//dynamixels[0]->getDynamixel()->getControlTable()->setReturnDelayTime(std::stoi(delai->getTextString()));
				dynamixels[0]->getDynamixel()->getControlTable()->setTorqueLimit(std::stoi(couple->getTextString()));
				dynamixels[0]->getDynamixel()->getControlTable()->setLowestByteOfMaxTorque(std::stoi(couple->getTextString()));
				dynamixels[0]->getDynamixel()->getControlTable()->setCCWAngleLimit(std::stoi(angle_max->getTextString()));
				dynamixels[0]->getDynamixel()->getControlTable()->setCWAngleLimit(std::stoi(angle_max->getTextString()));
				dynamixels[0]->getDynamixel()->setPositionMinimum(std::stoi(angle_min->getTextString()) * 3.413);
				dynamixels[0]->getDynamixel()->setPositionMaximum(std::stoi(angle_max->getTextString()) * 3.413);

				break;
			case 2:
				//dynamixels[1]->getDynamixel()->getControlTable()->setReturnDelayTime(std::stoi(delai->getTextString()));
				dynamixels[1]->getDynamixel()->getControlTable()->setTorqueLimit(std::stoi(couple->getTextString()));
				dynamixels[1]->getDynamixel()->getControlTable()->setLowestByteOfMaxTorque(std::stoi(couple->getTextString()));
				dynamixels[1]->getDynamixel()->getControlTable()->setCCWAngleLimit(std::stoi(angle_max->getTextString()));
				dynamixels[1]->getDynamixel()->getControlTable()->setCWAngleLimit(std::stoi(angle_max->getTextString()));
				dynamixels[1]->getDynamixel()->setPositionMinimum(std::stoi(angle_min->getTextString()) * 3.413);
				dynamixels[1]->getDynamixel()->setPositionMaximum(std::stoi(angle_max->getTextString()) * 3.413);

				break;
			case 3:
				//dynamixels[2]->getDynamixel()->getControlTable()->setReturnDelayTime(std::stoi(delai->getTextString()));
				dynamixels[2]->getDynamixel()->getControlTable()->setTorqueLimit(std::stoi(couple->getTextString()));
				dynamixels[2]->getDynamixel()->getControlTable()->setLowestByteOfMaxTorque(std::stoi(couple->getTextString()));
				dynamixels[2]->getDynamixel()->getControlTable()->setCCWAngleLimit(std::stoi(angle_max->getTextString()));
				dynamixels[2]->getDynamixel()->getControlTable()->setCWAngleLimit(std::stoi(angle_max->getTextString()));
				dynamixels[2]->getDynamixel()->setPositionMinimum(std::stoi(angle_min->getTextString()) * 3.413);
				dynamixels[2]->getDynamixel()->setPositionMaximum(std::stoi(angle_max->getTextString()) * 3.413);

				break;
			case 4:
				dynamixels[3]->getDynamixel()->getControlTable()->setReturnDelayTime(std::stoi(delai->getTextString()));
				dynamixels[3]->getDynamixel()->getControlTable()->setTorqueLimit(std::stoi(couple->getTextString()));
				dynamixels[3]->getDynamixel()->getControlTable()->setLowestByteOfMaxTorque(std::stoi(couple->getTextString()));
				dynamixels[3]->getDynamixel()->getControlTable()->setCCWAngleLimit(std::stoi(angle_max->getTextString()));
				dynamixels[3]->getDynamixel()->getControlTable()->setCWAngleLimit(std::stoi(angle_max->getTextString()));
				dynamixels[3]->getDynamixel()->setPositionMinimum(std::stoi(angle_min->getTextString()) * 3.413);
				dynamixels[3]->getDynamixel()->setPositionMaximum(std::stoi(angle_max->getTextString()) * 3.413);

				break;
			default:
				break;
			}
		}
			
		

	}
}

void ofApp::setled(int id) {
	if (dynamixels[id]->getDynamixel()->getControlTable()->ledState() == 0) {
		dynamixels[id]->getDynamixel()->getControlTable()->setLed(1);
	}
	else {
		dynamixels[id]->getDynamixel()->getControlTable()->setLed(0);
	}
}

void ofApp::scanDynamixel(int max) 
{
	int p = 0;
	id_dynamixel.clear();
	for (int i = 0; i <= max; i++) {
		if (portConnexion->ping(i)) {
			id_dynamixel.push_back(i);
		}
	}
}

void ofApp::setGUI5()
{
	gui5 = new ofxUISuperCanvas("        Movement");

	gui5->addSpacer();
	gui5->addLabel("Dynamixel ID", OFX_UI_FONT_SMALL);
	std::vector<string> id_dyna = { "1", "2", "3", "4" };
	ids = gui5->addDropDownList("Dynamixel", id_dyna);
	ids->setAutoClose(true);
	ids->setAllowMultiple(false);

	string textString = "Pour faire bouger un moteur dynamixel, ";
	textString += "Veuillez selectionner d'abord un ID en cliquant sur 'Dynamixel' au dessus.";
	textString += "La vue s'adapte a chaque fois qu'un nouvel ID est selectione pour afficher les informations correspondantes";

	gui5->addTextArea("textarea", textString, OFX_UI_FONT_SMALL);

	gui5->addSpacer();
	gui5->addLabel("Goal Position", OFX_UI_FONT_SMALL);
	rotation = gui5->addRotarySlider("The angle", 0, 300, 60);
	gui5->setPosition(300, 10);
	gui5->addSpacer();
	gui5->addToggle("Central position", false);

	gui5->addSpacer();
	gui5->addLabel("Goal Position", OFX_UI_FONT_SMALL);
	gui5->addTextInput("pos", "")->setAutoClear(true);
	gui5->addLabel("Moving speed", OFX_UI_FONT_SMALL);
	gui5->addTextInput("vit", "")->setAutoClear(true);
	/*
	gui5->addLabel("Acceleration ", OFX_UI_FONT_SMALL);
	gui5->addTextInput("Acceleration", "")->setAutoClear(true);
	gui5->addLabel("Freinage ", OFX_UI_FONT_SMALL);
	gui5->addTextInput("Freinage", "")->setAutoClear(true);
	*/
	//gui1->addSpacer();
	gui5->addLabelButton("Move", false, false);
	
	gui5->addSpacer();
	gui5->addToggle("LED on/off", false);

	gui5->setWidgetFontSize(OFX_UI_FONT_SMALL);
	gui5->autoSizeToFitWidgets();

	ofAddListener(gui5->newGUIEvent, this, &ofApp::guiEvent);
}


void ofApp::setGUI1()
{
	gui1 = new ofxUISuperCanvas("         Connexion");

	/*gui1->addSpacer();
	gui1->addLabel("USB2Dynamixel ports : ", OFX_UI_FONT_SMALL);
	std::vector<string> id_dyna = { "COM1", "COM2", "COM3", "COM4","COM5", "COM6", "COM7", "COM8" };
	ids = gui1->addDropDownList("Ports", id_dyna);
	ids->setAutoClose(true);
	ids->setAllowMultiple(false);

	gui1->addSpacer();
	gui1->addLabel("Baudrates ", OFX_UI_FONT_SMALL);
	std::vector<string> baudrate = { "1000000", "500000", "400000", "250000","200000", "117647", "57142", "19230","9613" };
	ids = gui1->addDropDownList("Baudrate", baudrate);
	ids->setAutoClose(true);
	ids->setAllowMultiple(false);*/
	gui1->addSpacer();
	gui1->addLabel("USB2Dynamixel ports", OFX_UI_FONT_SMALL);
	gui1->addTextInput("Ports", "")->setAutoClear(true);

	gui1->addSpacer();
	gui1->addLabel("Baudrates", OFX_UI_FONT_SMALL);
	gui1->addTextInput("Baudrate", "")->setAutoClear(true);

	gui1->addSpacer();
	gui1->addLabel("Maximum ID", OFX_UI_FONT_SMALL);
	gui1->addTextInput("id_max", "")->setAutoClear(true);

	gui1->addSpacer();
	gui1->addLabelButton("Scan", false, false);
	gui1->addSpacer();
	errorScan = gui1->addLabel("", OFX_UI_FONT_SMALL);

	gui1->setPosition(10, 10);
	gui1->setWidgetFontSize(OFX_UI_FONT_SMALL);
	gui1->autoSizeToFitWidgets();


	ofAddListener(gui1->newGUIEvent, this, &ofApp::guiEvent);
}


void ofApp::setGUI2()
{
	gui2 = new ofxUISuperCanvas("   Motor configuration");

	gui2->addSpacer();
	gui2->addLabel("Dynamixel ID", OFX_UI_FONT_SMALL);
	std::vector<string> id_dyna = { "1", "2", "3", "4" };
	ids = gui2->addDropDownList("Dynamixel", id_dyna);
	ids->setAutoClose(true);
	ids->setAllowMultiple(false);

	/*gui2->addSpacer();
	gui2->addLabel("New ID", OFX_UI_FONT_SMALL);
	gui2->addTextInput("delai", "")->setAutoClear(true);*/
	gui2->addSpacer();
	gui2->addLabel("Maximum torque (0 - 1023) ", OFX_UI_FONT_SMALL);
	gui2->addTextInput("couple", "")->setAutoClear(true);
	
	gui2->addSpacer();
	gui2->addLabel("Angle limit (0° - 300°) ", OFX_UI_FONT_SMALL);
	gui2->addSpacer();
	gui2->addLabel("Minimum ", OFX_UI_FONT_SMALL);
	gui2->addTextInput("angle_min", "")->setAutoClear(true);
	gui2->addLabel("Maximum", OFX_UI_FONT_SMALL);
	gui2->addTextInput("angle_max", "")->setAutoClear(true);
	

	gui2->addSpacer();
	gui2->addLabelButton("Apply", false, false);

	gui2->addSpacer();
	error = gui2->addLabel("",  OFX_UI_FONT_SMALL);

	gui2->setPosition(10, 340);
	gui2->setWidgetFontSize(OFX_UI_FONT_SMALL);
	gui2->autoSizeToFitWidgets();

	ofAddListener(gui2->newGUIEvent, this, &ofApp::guiEvent);
}



void ofApp::connect(const char * portName, float protocolVersion, int baudrate, int max) {
	//printf("ofConnexion * portConnexion = new ofConnexion(COM4, 1.0, 57142);\n");

	if (portConnexion == NULL) {
		portConnexion = new ofConnexion(portName, protocolVersion, baudrate);
		//id_dynamixel =  int[256];
		/*
		Probelem avec la creation du port, ajout un contructeur avec l'd et le portConnexion directement
		la port sera créer en dehors de la class pour plus de comprenhobilité

		*/
		bool succesConnexion = portConnexion->open();
		//succesConnexion = portConnexion->open();
		printf("bool succesConnexion = portConnexion->open();\n");
		if (succesConnexion)
		{
			errorScan->setLabel("Succeeded to open the port!");
			printf("Succeeded to open the port!\n");

		}
		else
		{
			errorScan->setLabel("Failed to open the port!");
			printf("Failed to open the port!\n");
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
		}

		scanDynamixel(max);

		int s = 0;
		vector<int>::iterator v = id_dynamixel.begin();
		while (v != id_dynamixel.end()) {

			dynamixels[s++] = new ofDynamixelServo(*v, portConnexion, 0, 1023);
			v++;
			taille++;
		}

		for (int i = 0; i < taille; i++) {
			cout << dynamixels[i]->getDynamixel()->getControlTable()->modelNumber() << "\n";
			
		}
		dynamixels[0]->getDynamixel()->setPositionMinimum(0);
		dynamixels[0]->getDynamixel()->setPositionMaximum(1023);

		dynamixels[1]->getDynamixel()->setPositionMinimum(25);
		dynamixels[1]->getDynamixel()->setPositionMaximum(760);

		dynamixels[2]->getDynamixel()->setPositionMinimum(170);
		dynamixels[2]->getDynamixel()->setPositionMaximum(845);

		dynamixels[3]->getDynamixel()->setPositionMinimum(10);
		dynamixels[3]->getDynamixel()->setPositionMaximum(760);
		//dyna_1 = new ofDynamixelServo(1, portConnexion, 0, 1023);
		//dyna_2 = new ofDynamixelServo(2, portConnexion, 25, 760);
		//dyna_3 = new ofDynamixelServo(3, portConnexion, 170, 845);
		//dyna_4 = new ofDynamixelServo(4, portConnexion, 10, 760);
		//cout << "taille : " << taille; 
		cout << "\n";
		draw();

	}
	
}


void ofApp::setGUI3()
{
	gui3 = new ofxUISuperCanvas("Dynamixel detected");
	if (taille > 0) {
		for (int i = 0; i < taille; i++) {

			stringstream ss;
			ss << "Dynamixel ";
			ss << dynamixels[i]->getDynamixel()->getControlTable()->getID();
			ss << " [RX-";
			ss << dynamixels[i]->getDynamixel()->getControlTable()->modelNumber();;
			ss << "]";
			gui3->addSpacer();
			gui3->addLabel(ss.str() , OFX_UI_FONT_SMALL);
		}
	}
	
	
	gui3->setPosition(10, 225);
	gui3->setWidgetFontSize(OFX_UI_FONT_SMALL);
	gui3->autoSizeToFitWidgets();


	ofAddListener(gui1->newGUIEvent, this, &ofApp::guiEvent);
}