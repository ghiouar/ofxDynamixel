#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	control_table = new ofControlTable(1, new ofConnexion("COM4", 1.0, 57142));
	gui.setup(); 
	gui.setName("Control Table Information");
	gui.setSize(250, gui.getHeight());
	// RAM
	gui.add(identifier.setup("ID \t\t\t", ofToString(control_table->getID()), 250));
	gui.add(model_number.setup("Model Number \t\t", ofToString(control_table->modelNumber()), 250));
	gui.add(version_firmware.setup("Version of Firmware\t", ofToString(control_table->firmwareVersion()), 250));
	gui.add(baud_rate.setup("Baud Rate \t\t", ofToString(control_table->baudRate()), 250));
	gui.add(return_delay_time.setup("Return Delay Time\t", ofToString(control_table->returnDelay()), 250));
	gui.add(cw_angle_limit.setup("CW Angle Limit\t\t", ofToString(control_table->CWAngleLimit()), 250));
	gui.add(ccw_angle_limit.setup("CCW Angle Limit\t\t", ofToString(control_table->CCWAngleLimit()), 250));
	gui.add(temperature_limit.setup("The Limit Temperature \t", ofToString(control_table->limitTemperature()), 250));
	gui.add(voltage_limit_low.setup("The Low Limit Voltage \t", ofToString(control_table->lowestLimitVoltage()), 250));
	gui.add(voltage_limit_high.setup("The High Limit Voltage \t", ofToString(control_table->highestLimitVoltage()), 250));
	gui.add(max_torque.setup("Max torque\t\t", ofToString(control_table->lowestByteOfMaxTorque()), 250));
	gui.add(status_return_level.setup("Status Return Level \t", ofToString(control_table->statusReturnLevel()), 250));
	gui.add(alarm_led.setup("Alarm LED \t\t", ofToString(control_table->getAlarmLed()), 250));
	gui.add(alarm_shutdown.setup("Alarm Shutdown \t\t", ofToString(control_table->getAlarmShutdown()), 250));

	//  EEPROM
	gui.add(torque_enable.setup("Torque On/Off \t\t", ofToString(control_table->torqueEnabled()), 250));
	gui.add(led.setup("LED On/Off \t\t", ofToString(control_table->ledState()), 250));
	gui.add(cw_compliance_margin.setup("CW Compliance margin \t", ofToString(control_table->CWComplianceMargin()), 250));
	gui.add(ccw_compliance_margin.setup("CCW Compliance margin \t", ofToString(control_table->CCWComplianceMargin()), 250));
	gui.add(cw_compliance_slope.setup("CW Compliance slope \t", ofToString(control_table->CWComplianceSlope()), 250));
	gui.add(ccw_compliance_slope.setup("CCW Compliance slope \t", ofToString(control_table->CCWComplianceSlope()), 250));
	gui.add(goal_position.setup("Goal Position \t\t", ofToString(control_table->goalPosition()), 250));
	gui.add(moving_speed.setup("Moving Speed \t\t", ofToString(control_table->movingSpeed()), 250));
	gui.add(torque_limit.setup("Torque Limit \t\t", ofToString(control_table->torqueLimit()), 250));
	gui.add(present_position.setup("Present Position \t", ofToString(control_table->presentPosition()), 250));
	gui.add(present_speed.setup("Present Speed \t\t", ofToString(control_table->presentSpeed()), 250));
	gui.add(present_load.setup("Present Load \t\t", ofToString(control_table->presentLoad()), 250));
	gui.add(present_voltage.setup("Present Voltage \t", ofToString(control_table->presentVoltage()), 250));
	gui.add(present_temperature.setup("Present Temperature \t", ofToString(control_table->presentTemperature()), 250));
	gui.add(moving.setup("Moving \t\t\t", ofToString(control_table->moving()), 250));
	gui.add(lockeeprom.setup("Locking EEPROM \t\t", ofToString(control_table->EEPROMLocked()), 250));
	gui.add(punch.setup("Lowest byte of Punch \t", ofToString(control_table->punch()), 250));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
