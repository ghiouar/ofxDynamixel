#include "ofDynamixel.h"
#include "stdafx.h"


ofDynamixel::ofDynamixel(int id, ofConnexion * portHandler, int position_min, int position_max)
{
	this->id = id;
	this->positionMinimum = position_min;
	this->positionMaximum = position_max;
	this->turnsCount = 0;
	this->portHandler = portHandler;
	this->controlTable = new ofControlTable(id, portHandler);

}

ofDynamixel::ofDynamixel(int id, char * device_name, float protocol_version, int baudrate, int position_min, int position_max)
{
	this->id = id; 
	this->positionMinimum = position_min;
	this->positionMaximum = position_max;
	this->turnsCount = 0;
	this->portHandler = new ofConnexion(device_name, protocol_version, baudrate);
	this->controlTable = new ofControlTable(id, portHandler);
}

// update to save one construtor with initial value !!
ofDynamixel::ofDynamixel(int id, char * device_name, float protocol_version, int baudrate)
{
	this->id = id;
	this->positionMinimum = 0;
	this->positionMaximum = 0;
	this->turnsCount = 0;
	this->portHandler = new ofConnexion(device_name, protocol_version, baudrate);
	this->controlTable = new ofControlTable(id, portHandler);
}

ofDynamixel::ofDynamixel(int id, int position_min, int position_max)
{
	this->id = id;
	this->positionMinimum = position_min;
	this->positionMaximum = position_max;
	this->turnsCount = 0;
	this->portHandler = new ofConnexion();
	this->controlTable = new ofControlTable(id, portHandler);


}

ofDynamixel::ofDynamixel(int id)
{
	this->id = id;
	this->positionMinimum = 0;
	this->positionMaximum = 0;
	this->turnsCount = 0;
	this->portHandler = new ofConnexion();
	this->controlTable = new ofControlTable(id, portHandler);
}


ofDynamixel::~ofDynamixel()
{
	delete portHandler;
	delete controlTable;
}

int ofDynamixel::getID()
{
	return this->id;
}

char * ofDynamixel::getPortName()
{
	return this->portName;
}

double ofDynamixel::getProtocolVersion()
{
	return this->protocolVersion;
}

int ofDynamixel::getBaudrate()
{
	return this->baudrate;
}

int ofDynamixel::getPositionMinimum()
{
	return this->positionMinimum;
}

int ofDynamixel::getPositionMaximum()
{
	return this->positionMaximum;
}

int ofDynamixel::getTurnsCount()
{
	return this->turnsCount;
}

ofControlTable * ofDynamixel::getControlTable()
{
	return this->controlTable;
}

ofConnexion * ofDynamixel::getPortHandler()
{
	return this->portHandler;
}

void ofDynamixel::setID(int id)
{
	this->id = id;
}

void ofDynamixel::setPositionMinimum(int positionMinimum)
{
	this->positionMinimum = positionMinimum;
}

void ofDynamixel::setPositionMaximum(int positionMaximum)
{
	this->positionMaximum = positionMaximum;
}

void ofDynamixel::setTurnsCount(int turnsCount)
{
	this->turnsCount = turnsCount;
}

void ofDynamixel::setControlTable(ofControlTable * controlTable)
{
	this->controlTable = controlTable;
}

void ofDynamixel::setPortHandler(ofConnexion * portHandler)
{
	this->portHandler = portHandler;
	this->controlTable = new ofControlTable(id, portHandler); 

}

bool ofDynamixel::ping()
{
	uint8_t error = 0;
	error = this->portHandler->getPacketHandler()->ping(this->portHandler->getPortHandler(), this->id, &error);
	if (error != 0) {
		return false;
	}
	return true;
}

bool ofDynamixel::Reset()
{
	uint8_t error = 0;
	error = this->portHandler->getPacketHandler()->factoryReset(this->portHandler->getPortHandler(), this->id, error);
	if (error != 0) {
		return false;
	}
	return true;
}

bool ofDynamixel::Initialize()
{
	uint8_t error = 0;
	this->portHandler->getPortHandler()->clearPort();
	if (error != 0) {
		return false;
	} // verife error 
	return true;
}


void ofDynamixel::Stop()
{
	this->portHandler->close();
}

bool ofDynamixel::reboot()
{
	uint8_t error = 0;
	error = this->portHandler->getPacketHandler()->reboot(this->portHandler->getPortHandler(), this->id, &error);
	if (error != 0) {
		return false;
	}
	return true;
}

bool ofDynamixel::move(int goalPosition, int movingSpeed)
{
	if (movingSpeed >= 0) {
		this->controlTable->setMovingSpeed(movingSpeed);
	}
	return this->controlTable->setGoalPosition(goalPosition);
}

void ofDynamixel::moveWithAcceleration(int goalPosition, int movingSpeed, int accelerationSpeed)
{
	int acceleration = accelerationSpeed;
	int position = accelerationSpeed;
	int movingspeed = 0;
	int i = 1;
	while (movingspeed < movingSpeed) {
		while (this->controlTable->moving()) {
		}
		this->controlTable->setMovingSpeed(accelerationSpeed * i);
		this->controlTable->setGoalPosition(position * i);
		i++;
		movingspeed = acceleration * i;

	}
	this->controlTable->setMovingSpeed(movingSpeed);
	this->controlTable->setGoalPosition(goalPosition);
}