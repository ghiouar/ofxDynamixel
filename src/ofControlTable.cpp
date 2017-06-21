#include "dynamixel_sdk.h"
#include "ofControlTable.h"
#include "ofRegister.h"
#include "ofConnexion.h"
#include "stdafx.h"



ofControlTable::ofControlTable(int id, ofConnexion * connexion)
{
	this->id = id;
	this->connexion = connexion;
	this->error = 0;
	this->data1Byte = 0;
}


ofControlTable::~ofControlTable()
{
	delete this->connexion;
}

ofConnexion * ofControlTable::getConnexion()
{
	return this->connexion;
}


void ofControlTable::readData(uint16_t address) {
	if (address == 8 || address == 14 || address == 30 || address == 34 || address == 36 )
	{
		connexion->getPacketHandler()->read2ByteTxRx(connexion->getPortHandler(), id, address, &data2Byte, &error);
	}
	else
	{
		connexion->getPacketHandler()->read1ByteTxRx(connexion->getPortHandler(), id, address, &data1Byte, &error);
	}
}

int ofControlTable::writeData(int address, int dataChange) {
	if (address == 8 || address == 14 || address == 30 || address == 34 || address == 36 || address == 32 )
	{
		return connexion->getPacketHandler()->write2ByteTxRx(connexion->getPortHandler(), id, address, dataChange, &error);
	}
	else
	{
		return connexion->getPacketHandler()->write1ByteTxRx(connexion->getPortHandler(), id, address, dataChange, &error);
	}
}
int ofControlTable::modelNumber()
{
	this->readData((uint16_t)ofRegister::MODEL_NUMBER);
	return data1Byte;
}
int ofControlTable::firmwareVersion()
{
	this->readData((uint16_t)ofRegister::VERSION_FIRMWARE);
	return data1Byte;
}
int ofControlTable::getID()
{
	return this->id;
}
int ofControlTable::baudRate()
{
	this->readData((uint16_t)ofRegister::BAUD_RATE);
	return data1Byte;
}

int ofControlTable::returnDelay()
{
	this->readData((uint16_t)ofRegister::RETURN_DELAY_TIME);
	return data1Byte;
}

int ofControlTable::CWAngleLimit()
{
	this->readData((uint16_t)ofRegister::CW_ANGLE_LIMIT);
	return data1Byte;
}

int ofControlTable::CCWAngleLimit()
{
	this->readData((uint16_t)ofRegister::CCW_ANGLE_LIMIT);
	return data2Byte;
}

int ofControlTable::limitTemperature()
{
	this->readData((uint16_t)ofRegister::TEMPERATURE_LIMIT);
	return data1Byte;
}

int ofControlTable::lowestLimitVoltage()
{
	this->readData((uint16_t)ofRegister::VOLTAGE_LIMIT_LOW);
	return data1Byte;
}

int ofControlTable::highestLimitVoltage()
{
	this->readData((uint16_t)ofRegister::VOLTAGE_LIMIT_HIGH);
	return data1Byte;
}


int ofControlTable::lowestByteOfMaxTorque()
{
	this->readData((uint16_t)ofRegister::MAX_TORQUE);
	return data2Byte;
}

int ofControlTable::statusReturnLevel()
{
	this->readData((uint16_t)ofRegister::STATUS_RETURN_LEVEL);
	return data1Byte;
}

int ofControlTable::getAlarmLed()
{
	this->readData((uint16_t)ofRegister::ALARM_LED);
	return data1Byte;
}
int ofControlTable::getAlarmShutdown()
{
	this->readData((uint16_t)ofRegister::ALARM_SHUTDOWN);
	return data1Byte;
}

bool ofControlTable::setId(uint8_t newId)
{
	return writeData((uint16_t)ofRegister::ID, newId);
	this->id = newId;
}

bool ofControlTable::setReturnDelayTime(int delay)
{
	return writeData((uint16_t)ofRegister::RETURN_DELAY_TIME, delay);
}

bool ofControlTable::setCWAngleLimit(int limit)
{
	return writeData((uint16_t)ofRegister::RETURN_DELAY_TIME, limit);
}

bool ofControlTable::setCCWAngleLimit(int limit)

{
	return writeData((uint16_t)ofRegister::RETURN_DELAY_TIME, limit);
}

bool ofControlTable::setLimitTemperature(unsigned char limitTemp)
{
	return writeData((uint16_t)ofRegister::RETURN_DELAY_TIME, limitTemp);
}

bool ofControlTable::setLowestLimitVoltage(int limitvoltage)
{
	return writeData((uint16_t)ofRegister::RETURN_DELAY_TIME, limitvoltage);
}

bool ofControlTable::setHighestLimitVoltage(int limitvoltage)
{
	return writeData((uint16_t)ofRegister::VOLTAGE_LIMIT_HIGH, limitvoltage);
}

bool ofControlTable::setLowestByteOfMaxTorque(int maxTorque)
{
	return writeData((uint16_t)ofRegister::MAX_TORQUE, maxTorque);
}

bool ofControlTable::setStatusReturnLevel(int level)
{
	return writeData((uint16_t)ofRegister::STATUS_RETURN_LEVEL, level);
}
bool ofControlTable::setAlarmLed(bool alarmedLed)
{
	return writeData((uint16_t)ofRegister::ALARM_LED, alarmedLed);
}

bool ofControlTable::setAlarmShutdown(bool shutdonw)
{
	return writeData((uint16_t)ofRegister::ALARM_SHUTDOWN, shutdonw);
}

// RAM
bool ofControlTable::torqueEnabled()
{
	this->readData((uint16_t)ofRegister::TORQUE_ENABLE);
	return data1Byte;
}

bool ofControlTable::ledState()
{
	this->readData((uint16_t)ofRegister::LED);
	return data1Byte;
}

int	ofControlTable::CWComplianceMargin()
{
	this->readData((uint16_t)ofRegister::CW_COMPLIANCE_MARGIN);
	return data1Byte;
}

int	ofControlTable::CCWComplianceMargin()
{
	this->readData((uint16_t)ofRegister::CCW_COMPLIANCE_MARGIN);
	return data1Byte;
}

int	ofControlTable::CWComplianceSlope()
{
	this->readData((uint16_t)ofRegister::CW_COMPLIANCE_SLOPE);
	return data1Byte;
}

int	ofControlTable::CCWComplianceSlope()
{
	this->readData((uint16_t)ofRegister::CCW_COMPLIANCE_SLOPE);
	return data1Byte;
}

int ofControlTable::goalPosition()
{
	this->readData((uint16_t)ofRegister::GOAL_POSITION);
	return data2Byte;
}

int ofControlTable::movingSpeed()
{
	this->readData((uint16_t)ofRegister::MOVING_SPEED);
	return data1Byte;
}

int ofControlTable::torqueLimit()
{
	this->readData((uint16_t)ofRegister::TORQUE_LIMIT);
	return data2Byte;
}

int ofControlTable::presentPosition()
{
	this->readData((uint16_t)ofRegister::PRESENT_POSITION);
	return data2Byte;
}

int ofControlTable::presentSpeed()
{
	this->readData((uint16_t)ofRegister::PRESENT_SPEED);
	return data1Byte;
}

int ofControlTable::presentLoad()
{
	this->readData((uint16_t)ofRegister::PRESENT_LOAD);
	return data1Byte;
}

int	ofControlTable::presentVoltage()
{
	this->readData((uint16_t)ofRegister::PRESENT_VOLTAGE);
	return data1Byte;
}

int	ofControlTable::presentTemperature()
{
	this->readData((uint16_t)ofRegister::PRESENT_TEMPERATURE);
	return data1Byte;
}

bool ofControlTable::instructionRegistered()
{
	this->readData((uint16_t)ofRegister::REDG);
	return data1Byte;
}

bool ofControlTable::moving()
{
	this->readData((uint16_t)ofRegister::MOVING);
	return data1Byte;
}

bool ofControlTable::EEPROMLocked()
{
	this->readData((uint16_t)ofRegister::LOCKEEPROM);
	return data1Byte;
}

int	ofControlTable::punch()
{
	this->readData((uint16_t)ofRegister::PUNCH);
	return data1Byte;
}

bool ofControlTable::enableTorque(bool torque)
{
	return writeData((uint16_t)ofRegister::TORQUE_ENABLE, torque);
}

bool ofControlTable::setLed(int led)
{
	return writeData((uint16_t)ofRegister::LED, led);
}

bool ofControlTable::setCWComplianceMargin(int CWComplianceMargin)
{
	return writeData((uint16_t)ofRegister::CW_COMPLIANCE_MARGIN, CWComplianceMargin);
}

bool ofControlTable::setCCWComplianceMargin(int CCWComplianceMargin)
{
	return writeData((uint16_t)ofRegister::CCW_COMPLIANCE_MARGIN, CCWComplianceMargin);
}

bool ofControlTable::setCWComplianceSlope(int CWComplianceSlope)
{
	return writeData((uint16_t)ofRegister::CW_COMPLIANCE_SLOPE, CWComplianceSlope);
}

bool ofControlTable::setCCWComplianceSlope(int CCWComplianceSlope)
{
	return writeData((uint16_t)ofRegister::CCW_COMPLIANCE_SLOPE, CCWComplianceSlope);
}

bool ofControlTable::setGoalPosition(int goal_postion)
{
	return writeData((uint16_t)ofRegister::GOAL_POSITION, goal_postion);

}

bool ofControlTable::setMovingSpeed(int movingSpeed)
{
	return writeData((uint16_t)ofRegister::MOVING_SPEED, movingSpeed);
}

bool ofControlTable::setTorqueLimit(int torqueLimit)
{
	return writeData((uint16_t)ofRegister::TORQUE_LIMIT, torqueLimit);
}

bool ofControlTable::lockEEPROM()
{
	return writeData((uint16_t)ofRegister::LOCKEEPROM, 1);
}

bool ofControlTable::unlockEEPROM()
{
	return writeData((uint16_t)ofRegister::LOCKEEPROM, 0);
}

int	ofControlTable::setPunch(int punch)
{
	return writeData((uint16_t)ofRegister::PUNCH, punch);
}
