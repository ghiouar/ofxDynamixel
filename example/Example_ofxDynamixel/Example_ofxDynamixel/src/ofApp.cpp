#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	printf("ofConnexion * portConnexion = new ofConnexion(COM4, 1.0, 57142);\n");
	ofConnexion * portConnexion = new ofConnexion("COM4", 1.0, 57142);

	/*
	Probelem avec la creation du port, ajout un contructeur avec l'd et le portConnexion directement
	la port sera créer en dehors de la class pour plus de comprenhobilité 
	
	*/
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

		dyna_1 = new ofDynamixelServo(1, portConnexion, 0,1023);
		//dyna_2 = new ofDynamixelServo(2, portConnexion, 25,760);
		//dyna_3 = new ofDynamixelServo(3, portConnexion, 170,845);
		//dyna_4 = new ofDynamixelServo(4, portConnexion, 10,760);




		setGUI5();
		setGUI1();
		


}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	gui5->draw();
	gui1->draw();
	dyna_1->draw();

	//dyna_1->draw();
	//dyna_2->draw();
	//dyna_3->draw();
	//dyna_4->draw();

	//dyna_1->hide();
	//dyna_2->hide();
	//dyna_3->hide();
	//dyna_4->hide();

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
		dyna_1->draw();
		dyna_2->hide();
		dyna_3->hide();
		dyna_4->hide();
		cout << "Dynamixel 1" << endl;
		id = 1;
		rotation->setMin(dyna_1->getMinPosition() / 3.413);
		rotation->setMax(dyna_1->getMaxPosition() / 3.413);
		
	} else if (name == "2")
	{
		dyna_1->hide();
		dyna_2->draw();
		dyna_3->hide();
		dyna_4->hide();
		cout << "Dynamixel 2" << endl;
		id = 2;
		rotation->setMin(dyna_2->getMinPosition()/ 3.413);
		rotation->setMax(dyna_2->getMaxPosition()/ 3.413);

	} else if (name == "3")
	{
		dyna_1->hide();
		dyna_2->hide();
		dyna_3->draw();
		dyna_4->hide();
		cout << "Dynamixel 3" << endl;
		id = 3;
		rotation->setMin(dyna_3->getMinPosition() / 3.413);
		rotation->setMax(dyna_3->getMaxPosition() / 3.413);

	} else if (name == "4")
	{
		dyna_1->hide();
		dyna_2->hide();
		dyna_3->hide();
		dyna_4->draw();
		cout << "Dynamixel 4" << endl;
		id = 4;
		rotation->setMin(dyna_4->getMinPosition() / 3.413);
		rotation->setMax(dyna_4->getMaxPosition() / 3.413);

	}

	if (name == "L'angle")
	{
		ofxUIRotarySlider *radio = (ofxUIRotarySlider *)e.widget;
		cout << " Angle: " << radio->getValue() << endl;
		float new_position = radio->getValue();
		switch (id)
		{
		case 1: dyna_1->change(new_position * 3.413); cout << "1"; break;
		case 2: dyna_2->change(new_position * 3.413); cout << "2"; break;
		case 3: dyna_3->change(new_position * 3.413); cout << "3"; break;
		case 4: dyna_4->change(new_position * 3.413); cout << "4"; break;
		default:
			break;
		}

	}
	if (name == "Bouger")
	{
		ofxUITextInput *Vitesse = (ofxUITextInput *)gui5->getWidget("Vitesse");
		ofxUITextInput *Acceleration = (ofxUITextInput *)gui5->getWidget("Acceleration");
		ofxUITextInput *Freinage = (ofxUITextInput *)gui5->getWidget("Freinage");

		cout << "\nStart Move acceleraztion : " << endl;
		cout << Vitesse->getName() << " value: " << Vitesse->getTextString() << endl;
		cout << Acceleration->getName() << " value: " << Acceleration->getTextString() << endl;
		cout << Freinage->getName() << " value: " << Freinage->getTextString() << endl;
		cout << "End Move acceleraztion \n" << endl;
	}
}

void ofApp::setGUI5()
{
	gui5 = new ofxUISuperCanvas("        Déplacement");

	gui5->addSpacer();
	gui5->addLabel("Dynamixel ID", OFX_UI_FONT_SMALL);
	std::vector<string> id_dyna = { "1", "2", "3", "4" };
	ids = gui5->addDropDownList("Dynamixel", id_dyna);
	ids->setAutoClose(true);
	ids->setAllowMultiple(false);

	string textString = "Pour faire bouger un moteur dynamixel, ";
	textString += "Veuillez séléctionner d'abord un ID en cliqant sur 'Dynamixel' au dessus.";
	textString += "La vue s'apadte a chaque fois qu'un nouvel ID est séléctioner pour afficher les informations correspondantes";
	//gui5->addSpacer();

	gui5->addTextArea("textarea", textString, OFX_UI_FONT_SMALL);

	/*gui5->addLabel("Connecter", OFX_UI_FONT_SMALL);
	gui5->addLabelButton("Connecter", false, false);
	gui5->setPosition(212 * 3, 100);*/



	gui5->addSpacer();
	gui5->addLabel("Déplacement angulaire", OFX_UI_FONT_SMALL);
	rotation = gui5->addRotarySlider("L'angle", 0, 300, 60);
	gui5->setPosition(212 * 3, 10);



	/* Button connecter*/
	/*gui5->addSpacer();
	gui5->addLabel("Connecter", OFX_UI_FONT_SMALL);
	gui5->addLabelButton("Connecter", false, false);
	gui5->setPosition(212 * 3, 100);*/



	gui5->addSpacer();
	gui5->addLabel("Vitesse max ", OFX_UI_FONT_SMALL);
	gui5->addTextInput("Vitesse", "")->setAutoClear(true);
	gui5->addLabel("Acceleration ", OFX_UI_FONT_SMALL);
	gui5->addTextInput("Acceleration", "")->setAutoClear(true);
	gui5->addLabel("Freinage ", OFX_UI_FONT_SMALL);
	gui5->addTextInput("Freinage", "")->setAutoClear(true);
	gui5->addLabelButton("Bouger", false, false);
	


	

	gui5->setWidgetFontSize(OFX_UI_FONT_SMALL);
	gui5->autoSizeToFitWidgets();

	ofAddListener(gui5->newGUIEvent, this, &ofApp::guiEvent);
}


void ofApp::setGUI1()
{
	gui1 = new ofxUISuperCanvas("Update Control Table");

	gui1->addSpacer();
	gui1->addLabel("Dynamixel ID", OFX_UI_FONT_SMALL);
	std::vector<string> id_dyna = { "1", "2", "3", "4" };
	ids = gui1->addDropDownList("Dynamixel", id_dyna);
	ids->setAutoClose(true);
	ids->setAllowMultiple(false);

	string textString = "Pour faire bouger un moteur dynamixel, ";
	textString += "Veuillez séléctionner d'abord un ID en cliqant sur 'Dynamixel' au dessus.";
	textString += "La vue s'apadte a chaque fois qu'un nouvel ID est séléctioner pour afficher les informations correspondantes";
	//gui5->addSpacer();

	gui1->addTextArea("textarea", textString, OFX_UI_FONT_SMALL);

	/*gui5->addLabel("Connecter", OFX_UI_FONT_SMALL);
	gui5->addLabelButton("Connecter", false, false);
	gui5->setPosition(212 * 3, 100);*/



	gui1->addSpacer();
	gui1->addLabel("Déplacement angulaire", OFX_UI_FONT_SMALL);
	rotation = gui1->addRotarySlider("L'angle", 0, 300, 60);
	gui1->setPosition(170 * 2, 10);



	/* Button connecter*/
	/*gui5->addSpacer();
	gui5->addLabel("Connecter", OFX_UI_FONT_SMALL);
	gui5->addLabelButton("Connecter", false, false);
	gui5->setPosition(212 * 3, 100);*/



	gui1->addSpacer();
	gui1->addLabel("Vitesse max ", OFX_UI_FONT_SMALL);
	gui1->addTextInput("Vitesse", "")->setAutoClear(true);
	gui1->addLabel("Acceleration ", OFX_UI_FONT_SMALL);
	gui1->addTextInput("Acceleration", "")->setAutoClear(true);
	gui1->addLabel("Freinage ", OFX_UI_FONT_SMALL);
	gui1->addTextInput("Freinage", "")->setAutoClear(true);
	gui1->addLabelButton("Bouger", false, false);





	gui1->setWidgetFontSize(OFX_UI_FONT_SMALL);
	gui1->autoSizeToFitWidgets();

	ofAddListener(gui1->newGUIEvent, this, &ofApp::guiEvent);
}
