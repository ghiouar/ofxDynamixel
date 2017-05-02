#include "ofDynamixel.h"
#include "stdafx.h"


ofDynamixel::ofDynamixel(int id, char * device_name, double protocol_version, int baudrate, int position_min, int position_max)
{
	this->id = id; this->positionMinimum = position_min;
	this->positionMaximum = position_max;
	this->turnsCount = 0;
	this->portHundler = new ofConnexion(device_name, protocol_version, baudrate);
	this->control_table = new ofControlTable(id, portHundler);
}

ofDynamixel::ofDynamixel(int id, char * device_name, double protocol_version, int baudrate)
{
	this->id = id;
	this->positionMinimum = 0;
	this->positionMaximum = 0;
	this->turnsCount = 0;
	this->portHundler = new ofConnexion(device_name, protocol_version, baudrate);
	this->control_table = new ofControlTable(id, portHundler);
}

ofDynamixel::ofDynamixel(int id, int position_min, int position_max)
{
	this->id = id;
	this->positionMinimum = position_min;
	this->positionMaximum = position_max;
	this->turnsCount = 0;
	this->portHundler = new ofConnexion();
	this->control_table = new ofControlTable(id, portHundler);


}

ofDynamixel::ofDynamixel(int id)
{
	this->id = id;
	this->positionMinimum = 0;
	this->positionMaximum = 0;
	this->turnsCount = 0;
	this->portHundler = new ofConnexion();
	this->control_table = new ofControlTable(id, portHundler);
}


ofDynamixel::~ofDynamixel()
{
	delete portHundler;
	delete control_table;
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
	return baudrate;
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
	return this->control_table;
}

ofConnexion * ofDynamixel::getPortHundler()
{
	return this->portHundler;
}

void ofDynamixel::setID(int id)
{
	this->id = id;
}

void ofDynamixel::setPositionMinimum(int position_min)
{
	this->positionMinimum = position_min;
}

void ofDynamixel::setPositionMaximum(int position_max)
{
	this->positionMaximum = position_max;
}

void ofDynamixel::setTurnsCount(int turns_count)
{
	this->turnsCount = turns_count;
}

void ofDynamixel::setControlTable(ofControlTable * control_table)
{
	this->control_table = control_table;
}

void ofDynamixel::setPortHundler(ofConnexion * portHundler)
{
	this->portHundler = portHundler;
}

bool ofDynamixel::ping()
{
	uint8_t error = 0;
	return this->portHundler->getPacketHandler()->ping(this->portHundler->getPortHandler(), this->id, &error);
	if (error != 0) {
		return false;
	}
	return true;
}

bool ofDynamixel::Reset()
{
	return false;
}

bool ofDynamixel::Initialize()
{
	return false;
}

bool ofDynamixel::Synchronize()
{
	return false;
}

bool ofDynamixel::Stop()
{
	return false;
}

bool ofDynamixel::reboot()
{
	return false;
}
