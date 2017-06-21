#include <sstream>
#include <string>
#include "ofDynamixelServo.h"
#include "ofxDynamixel/src/ofConnexion.h"
#include "ofxDynamixel/src/ofControlTable.h"

//--------------------------------------------------------------

ofDynamixelServo::ofDynamixelServo(int id, ofConnexion * portConnexion, int minPosition, int maxPosition) {
	//control_table = new ofControlTable(id, portConnexion);
	this->dynamixel = new ofDynamixel(id, "COM4", 1.0, 57142, minPosition, maxPosition);
	this->minPosition = minPosition;
	this->maxPosition = maxPosition;
	this->dynamixel->setPortHandler(portConnexion);
	if (dynamixel->getControlTable() != NULL) {
		printf("Go\n");
	 }
	control_table = this->dynamixel->getControlTable();

	printf("ID \t\t\t\t: %d\n", control_table->getID());
	printf("Model Number \t\t\t: %d\n", control_table->modelNumber());
	printf("Version of Firmware\t\t: %d\n", control_table->firmwareVersion());
	printf("Baud Rate \t\t\t: %d\n", control_table->baudRate());

	setup();
}


void ofDynamixelServo::setup() {


	dynamixel_move.setup();
	std::stringstream ss;
	ss << "Moving, Dynamixel N° " << control_table->getID();
	dynamixel_move.setName(ss.str());
	dynamixel_move.setSize(250, control_table_infos.getHeight());
	dynamixel_move.setPosition(300, 10);
	ofxIntSlider * dyna  = new  ofxIntSlider();
	int presentPostion = this->dynamixel->getControlTable()->presentPosition();
	dynamixel_move.add(dyna->setup("Position Goal", presentPostion, minPosition, maxPosition,250,15));
	dyna->addListener(this, &ofDynamixelServo::positionChanged); // after for no change when start program
	read_infos = new ofxButton();
	read_infos->setName("Connecter");
	read_infos->draw();
	//dynamixel_move.add(read_infos);
	
	//setGUI5();
	update();
}


void ofDynamixelServo::positionChanged(int &goalPosition) {
	control_table->setGoalPosition(goalPosition);
	//update();
}

void ofDynamixelServo::change(float goalPosition) {
	control_table->setGoalPosition(goalPosition);
	cout << "change\n";
	//update();
}

void ofDynamixelServo::move(float goalPosition, float movingSpeed)
{
	this->dynamixel->move(goalPosition, movingSpeed);
}

int ofDynamixelServo::getMinPosition()
{
	return minPosition;
}

int ofDynamixelServo::getMaxPosition()
{
	return maxPosition;
}

ofDynamixel * ofDynamixelServo::getDynamixel()
{
	return this->dynamixel;
}

ofxPanel ofDynamixelServo::getControl_table_infos()
{
	return control_table_infos;
}

//--------------------------------------------------------------
void ofDynamixelServo::update() {
	control_table_infos.setup();
		

	control_table_infos.setName("Control Table Information");
	control_table_infos.setSize(250, control_table_infos.getHeight());
	// RAM
	control_table_infos.add(identifier.setup("ID \t\t\t", ofToString(control_table->getID()), 250));
	control_table_infos.add(model_number.setup("Model Number \t\t", ofToString(control_table->modelNumber()), 250));
	//printf("ModelNumber : %d", control_table->modelNumber());
	control_table_infos.add(version_firmware.setup("Version of Firmware\t", ofToString(control_table->firmwareVersion()), 250));
	control_table_infos.add(baud_rate.setup("Baud Rate \t\t", ofToString(control_table->baudRate()), 250));
	control_table_infos.add(return_delay_time.setup("Return Delay Time\t", ofToString(control_table->returnDelay()), 250));
	control_table_infos.add(cw_angle_limit.setup("CW Angle Limit\t\t", ofToString(control_table->CWAngleLimit()), 250));
	control_table_infos.add(ccw_angle_limit.setup("CCW Angle Limit\t\t", ofToString(control_table->CCWAngleLimit()), 250));
	control_table_infos.add(temperature_limit.setup("The Limit Temperature \t", ofToString(control_table->limitTemperature()), 250));
	control_table_infos.add(voltage_limit_low.setup("The Low Limit Voltage \t", ofToString(control_table->lowestLimitVoltage()), 250));
	control_table_infos.add(voltage_limit_high.setup("The High Limit Voltage \t", ofToString(control_table->highestLimitVoltage()), 250));
	control_table_infos.add(max_torque.setup("Max torque\t\t", ofToString(control_table->lowestByteOfMaxTorque()), 250));
	control_table_infos.add(status_return_level.setup("Status Return Level \t", ofToString(control_table->statusReturnLevel()), 250));
	control_table_infos.add(alarm_led.setup("Alarm LED \t\t", ofToString(control_table->getAlarmLed()), 250));
	control_table_infos.add(alarm_shutdown.setup("Alarm Shutdown \t\t", ofToString(control_table->getAlarmShutdown()), 250));

	//  EEPROM
	control_table_infos.add(torque_enable.setup("Torque On/Off \t\t", ofToString(control_table->torqueEnabled()), 250));
	control_table_infos.add(led.setup("LED On/Off \t\t", ofToString(control_table->ledState()), 250));
	control_table_infos.add(cw_compliance_margin.setup("CW Compliance margin \t", ofToString(control_table->CWComplianceMargin()), 250));
	control_table_infos.add(ccw_compliance_margin.setup("CCW Compliance margin \t", ofToString(control_table->CCWComplianceMargin()), 250));
	control_table_infos.add(cw_compliance_slope.setup("CW Compliance slope \t", ofToString(control_table->CWComplianceSlope()), 250));
	control_table_infos.add(ccw_compliance_slope.setup("CCW Compliance slope \t", ofToString(control_table->CCWComplianceSlope()), 250));
	control_table_infos.add(goal_position.setup("Goal Position \t\t", ofToString(control_table->goalPosition()), 250));
	control_table_infos.add(moving_speed.setup("Moving Speed \t\t", ofToString(control_table->movingSpeed()), 250));
	control_table_infos.add(torque_limit.setup("Torque Limit \t\t", ofToString(control_table->torqueLimit()), 250));
	control_table_infos.add(present_position.setup("Present Position \t", ofToString(control_table->presentPosition()), 250));
	control_table_infos.add(present_speed.setup("Present Speed \t\t", ofToString(control_table->presentSpeed()), 250));
	control_table_infos.add(present_load.setup("Present Load \t\t", ofToString(control_table->presentLoad()), 250));
	control_table_infos.add(present_voltage.setup("Present Voltage \t", ofToString(control_table->presentVoltage()), 250));
	control_table_infos.add(present_temperature.setup("Present Temperature \t", ofToString(control_table->presentTemperature()), 250));
	control_table_infos.add(moving.setup("Moving \t\t\t", ofToString(control_table->moving()), 250));
	control_table_infos.add(lockeeprom.setup("Locking EEPROM \t\t", ofToString(control_table->EEPROMLocked()), 250));
	control_table_infos.add(punch.setup("Lowest byte of Punch \t", ofToString(control_table->punch()), 250));
}

//--------------------------------------------------------------
void ofDynamixelServo::draw() {
	control_table_infos.draw();
	//control_table_infos.setPosition(550, 10);
	//hide();
}

void ofDynamixelServo::hide() {
	control_table_infos.setPosition(1000, 1000);
}

void ofDynamixelServo::show() { 
	update();
	control_table_infos.setPosition(550, 10);
	//control_table_infos.setShape((500.0, 10.0,(float) control_table_infos.getWidth(), (float)control_table_infos.getHeight()));
	//control_table_infos.setShape(500.0, 10.0, (float)control_table_infos.getWidth(), (float)control_table_infos.getHeight());
}

//--------------------------------------------------------------
void ofDynamixelServo::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofDynamixelServo::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofDynamixelServo::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofDynamixelServo::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofDynamixelServo::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofDynamixelServo::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofDynamixelServo::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofDynamixelServo::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofDynamixelServo::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofDynamixelServo::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofDynamixelServo::dragEvent(ofDragInfo dragInfo) {

}


