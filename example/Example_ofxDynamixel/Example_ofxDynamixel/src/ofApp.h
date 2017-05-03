#pragma once

#include "ofMain.h"
#include "ofxGui/src/ofxGui.h"
#include "ofxDynamixel/src/ofConnexion.h"
#include "ofxDynamixel/src/ofControlTable.h"

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
	ofxPanel gui;
	ofxPanel gu;
	ofxButton read_infos;
	ofxLabel nom;
	ofxLabel model_number;
	ofxLabel version_firmware;
	ofxLabel identifier;
	ofxLabel baud_rate;
	ofxLabel return_delay_time;
	ofxLabel cw_angle_limit;
	ofxLabel ccw_angle_limit;
	ofxLabel temperature_limit;
	ofxLabel voltage_limit_low;
	ofxLabel voltage_limit_high;
	ofxLabel max_torque;
	ofxLabel status_return_level;
	ofxLabel alarm_led;
	ofxLabel alarm_shutdown;
	ofxLabel torque_enable;;
	ofxLabel led;
	ofxLabel cw_compliance_margin;
	ofxLabel ccw_compliance_margin;
	ofxLabel cw_compliance_slope;
	ofxLabel ccw_compliance_slope;
	ofxLabel goal_position;
	ofxLabel moving_speed;
	ofxLabel torque_limit;
	ofxLabel present_position;
	ofxLabel present_speed;
	ofxLabel present_load;
	ofxLabel present_voltage;
	ofxLabel present_temperature;
	ofxLabel redg;
	ofxLabel moving;
	ofxLabel lockeeprom;
	ofxLabel punch;
	ofxLabel goal_acceleration;

	ofControlTable * control_table;
	ofConnexion * connexion;

};
