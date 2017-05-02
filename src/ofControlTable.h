/*!
* \file		ofControlTable.h
* \brief	Declares the of control table class.

*/

#pragma once

#include "ofConnexion.h"
#include "dynamixel_sdk.h"

/*!
* \class	ofControlTable
*
* \brief	The ofControlTable class. Control Table consists of data regarding the
* 			current status and operation, which exists inside of Dynamixel. The user can
* 			control Dynamixel by changing data of Control Table via Instruction Packet.
*
* 			EEPROM and RAM EEPROM and RAM Data in RAM area is reset to the initial value whenever
* 			the power is turned on while data in EEPROM area is kept once the value is set even
* 			if the power is turned off.
*
* 			Address : Address It represents the location of data. To read from or write data to
* 			Control Table, the user should assign the correct address in the Instruction Packet.
*
* 			Access : Dynamixel has two kinds of data: Read-only data, which is mainly used for
* 			sensing, and Read-and-Write data, which is used for driving.
*
* 			Initial Value : Initial Value In case of data in the EEPROM Area, the initial values on
* 			the right side of the below Control Table are the factory default settings. In case
* 			of data in the RAM Area, the initial values on the right side of the above Control
* 			Tables are the ones when the power is turned on.
*
* 			Highest/Lowest Byte : Highest/Lowest Byte In the Control table, some data share the
* 			same name, but they are attached with (L) or (H) at the end of each name to
* 			distinguish the address. This data requires 16bit, but it is divided into 8bit each
* 			for the addresses (low) and (high). These two addresses should be written with one
* 			Instruction Packet at the same time.
*
* \author	Abdessalam Ghiouar
* \version	0.1
* \date		April 25, 2017
*/

class ofControlTable
{
public:

	/*!
	* \fn	ofControlTable::ofControlTable(int id, ofConnexion * connexion);
	* \brief	Constructor of the ofControlTable class, Creates instance of ofControlTable.
	* \param 		  	id		 	The Dynamixel ID.
	* \param [in,out]	connexion	The connexion instance with the Dynamixel.
	*/

	ofControlTable(int id, ofConnexion * connexion);

	/*!
	* \fn	ofControlTable::~ofControlTable();
	* \brief	~ofControlTable.
	*/

	~ofControlTable();

	/*!
	* \fn	ofConnexion * ofControlTable::getConnexion();
	* \brief	getConnexion get the connexion instance with the Dynamixel.
	* \return	The connexion instance with the Dynamixel.
	*/

	ofConnexion * getConnexion();

	/*!
	* \fn	void ofControlTable::readData(uint16_t address);
	*
	* \brief	readData Read the data of Control Table. The current status and operation, which
	* 			exists inside of Dynamixel.
	*
	* \param	address	The location of data in the Control Table.
	*/

	void readData(uint16_t address);

	/*!
	* \fn	int ofControlTable::writeData(int address, int dataChange);
	*
	* \brief	writeData Write/Update the data of Control Table.
	*
	* \param	address   	The location of data in the Control Table.
	* \param	dataChange	the new Data for the register specified by address.
	*
	* \return	An int.
	*/

	int writeData(int address, int dataChange);

	/*!
	* \fn	int ofControlTable::modelNumber();
	*
	* \brief	modelNumber Get the model number.
	*
	* \return	The model number.
	*/

	int modelNumber();

	/*!
	* \fn	int ofControlTable::firmwareVersion();
	*
	* \brief	firmwareVersion Get the firmware version.
	*
	* \return	The firmware version.
	*/

	int firmwareVersion();

	/*!
	* \fn	int ofControlTable::getID();
	*
	* \brief	getID Get the Dynamixel ID.
	*
	* \return	the Dynamixel ID.
	*/

	int getID();

	/*!
	* \fn	int ofControlTable::baudRate();
	*
	* \brief	baudRate Get the baud rate the Dynamixel will communicate at.
	*
	* \return	the baud rate the Dynamixel will communicate at.
	*/

	int baudRate();

	/*!
	* \fn	int ofControlTable::returnDelay();
	*
	* \brief	returnDelay Get The return delay.
	*
	* \return	the time it takes for a status packet to return after a command packet is sent.
	*/

	int returnDelay();

	/*!
	* \fn	int ofControlTable::CWAngleLimit();
	*
	* \brief	Get the CW angle limit for the Dynamixel's movement.
	*
	* \return	The Lowest byte of clockwise Angle Limit.
	*/

	int CWAngleLimit();

	/*!
	* \fn	int ofControlTable::CCWAngleLimit();
	*
	* \brief	CCWAngleLimit Get or set the CCW angle limit for the Dynamixel's movement.
	*
	* \return	The Lowest byte of counterclockwise Angle Limit.
	*/

	int CCWAngleLimit();

	/*!
	* \fn	int ofControlTable::limitTemperature();
	*
	* \brief	Get the temperature limit.
	*
	* \return	The Internal Limit Temperature.
	*/

	int limitTemperature();

	/*!
	* \fn	int ofControlTable::lowestLimitVoltage();
	*
	* \brief	Get the lowest voltage limit.
	*
	* \return	The Lowest Limit Voltage.
	*/

	int lowestLimitVoltage();

	/*!
	* \fn	int ofControlTable::highestLimitVoltage();
	*
	* \brief	Get the Highest voltage limit.
	*
	* \return	The Highest Limit Voltage.
	*/

	int highestLimitVoltage();

	/*!
	* \fn	int ofControlTable::lowestByteOfMaxTorque();
	*
	* \brief	Get the lowest byte of Max. Torque.
	*
	* \return	the Lowest byte of Max. Torque.
	*/

	int lowestByteOfMaxTorque();

	/*!
	* \fn	int ofControlTable::statusReturnLevel();
	*
	* \brief	Get the status return level. that determines when the dynamixel
	* 			will respond to command packets with a status packet.
	*
	* \return	the status return level.
	*/

	int statusReturnLevel();

	/*!
	* \fn	int ofControlTable::getAlarmLed();
	*
	* \brief	Get the error conditions that will result in lighting the LED.
	*
	* \return	LED for Alarm.
	*/

	int getAlarmLed();

	/*!
	* \fn	int ofControlTable::getAlarmShutdown();
	*
	* \brief	Get the error conditions that will result in Dynamixel shutdown.
	*
	* \return	Shutdown for Alarm.
	*/

	int getAlarmShutdown();

	/*!
	* \fn	bool ofControlTable::setId(uint8_t newId);
	*
	* \brief	Set the Dynamixel ID.
	*
	* \param	newId	the new Dynamixel ID.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setId(uint8_t newId);

	/*!
	* \fn	bool ofControlTable::setReturnDelayTime(int delay);
	*
	* \brief	Set The return delay.
	*
	* \param	delay	The new return delay.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setReturnDelayTime(int delay);

	/*!
	* \fn	bool ofControlTable::setCWAngleLimit(int limit);
	*
	* \brief	Set the CW angle limit for the Dynamixel's movement.
	*
	* \param	limit	The new limit for the Dynamixel's movement.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setCWAngleLimit(int limit);

	/*!
	* \fn	bool ofControlTable::setCCWAngleLimit(int limit);
	*
	* \brief	Set the CCW angle limit for the Dynamixel's movement.
	*
	* \param	limit	The new limit for the Dynamixel's movement.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setCCWAngleLimit(int limit);

	/*!
	* \fn	bool ofControlTable::setLimitTemperature(unsigned char limitTemp);
	*
	* \brief	Set the temperature limit.
	*
	* \param	limitTemp	The new temperature limit.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setLimitTemperature(unsigned char limitTemp);

	/*!
	* \fn	bool ofControlTable::setLowestLimitVoltage(int limitVoltage);
	*
	* \brief	Set the lowest voltage limit.
	*
	* \author	Agh
	* \date	28/04/2017
	*
	* \param	limitVoltage	The new temperature limit.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setLowestLimitVoltage(int limitVoltage);

	/*!
	* \fn	bool ofControlTable::setHighestLimitVoltage(int limitVoltage);
	*
	* \brief	Set the Highest voltage limit.
	*
	* \author	Agh
	* \date	28/04/2017
	*
	* \param	limitVoltage	The new Highest voltage limit.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setHighestLimitVoltage(int limitVoltage);

	/*!
	* \fn	bool ofControlTable::setLowestByteOfMaxTorque(int maxTorque);
	*
	* \brief	Set the lowest byte of Max. Torque.
	*
	* \param	maxTorque	The new lowest byte of Max. Torque.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setLowestByteOfMaxTorque(int maxTorque);

	/*!
	* \fn	bool ofControlTable::setStatusReturnLevel(int level);
	*
	* \brief	Set the status return level.
	*
	* \param	level	The new status return level.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setStatusReturnLevel(int level);

	/*!
	* \fn	bool ofControlTable::setAlarmLed(bool led);
	*
	* \brief	Set the error conditions that will result in lighting the LED.
	*
	* \param	led	The error conditions that will result in lighting the LED.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setAlarmLed(bool led);

	/*!
	* \fn	bool ofControlTable::setAlarmShutdown(bool shutdonw);
	*
	* \brief	Set the error conditions that will result in Dynamixel shutdown.
	*
	* \param	shutdonw	the error conditions that will result in Dynamixel shutdown.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setAlarmShutdown(bool shutdonw);

	// RAM

	/*!
	* \fn	bool ofControlTable::torqueEnabled();
	*
	* \brief	Get the torque enable.
	*
	* \return	True if the the torque is enabled, false otherwise.
	*/

	bool torqueEnabled();

	/*!
	* \fn	bool ofControlTable::ledState();
	*
	* \brief	Get state of the LED.
	*
	* \return	The state of the LED.
	*/

	bool ledState();

	/*!
	* \fn	int ofControlTable::CWComplianceMargin();
	*
	* \brief	Get the CW compliance margin.
	*
	* \return	The CW compliance margin.
	*/

	int	CWComplianceMargin();

	/*!
	* \fn	int ofControlTable::CCWComplianceMargin();
	*
	* \brief	Get the CCW compliance margin.
	*
	* \return	The CCW compliance margin.
	*/

	int	CCWComplianceMargin();

	/*!
	* \fn	int ofControlTable::CWComplianceSlope();
	*
	* \brief	Get the CW compliance slope.
	*
	* \return	The CW compliance slope.
	*/

	int	CWComplianceSlope();

	/*!
	* \fn	int ofControlTable::CCWComplianceSlope();
	*
	* \brief	Get the CCW compliance slope.
	*
	* \return	The CCW compliance slope.
	*/

	int	CCWComplianceSlope();

	/*!
	* \fn	int ofControlTable::goalPosition();
	*
	* \brief	Get the goal position register.
	*
	* \return	The goal position register.
	*/

	int goalPosition();

	/*!
	* \fn	int ofControlTable::movingSpeed();
	*
	* \brief	Get the moving speed register.
	*
	* \return	The moving speed register.
	*/

	int movingSpeed();

	/*!
	* \fn	int ofControlTable::torqueLimit();
	*
	* \brief	Get the torque limit.
	*
	* \return	The torque limit.
	*/

	int torqueLimit();

	/*!
	* \fn	int ofControlTable::presentPosition();
	*
	* \brief	Get the present position.
	*
	* \return	The present position.
	*/

	int presentPosition();

	/*!
	* \fn	int ofControlTable::presentSpeed();
	*
	* \brief	Get the present speed.
	*
	* \return	The present speed.
	*/

	int presentSpeed();

	/*!
	* \fn	int ofControlTable::presentLoad();
	*
	* \brief	Get the present load on the Dynamixel.
	*
	* \return	The present load on the Dynamixel.
	*/

	int presentLoad();

	/*!
	* \fn	int ofControlTable::presentVoltage();
	*
	* \brief	Get the present voltage.
	*
	* \return	The present voltage.
	*/

	int	presentVoltage();

	/*!
	* \fn	int ofControlTable::presentTemperature();
	*
	* \brief	Get the present temperature.
	*
	* \return	The present temperature.
	*/

	int	presentTemperature();

	/*!
	* \fn	bool ofControlTable::instructionRegistered();
	*
	* \brief	Get an indication of whether or not a RegWrite instruction is
	* 			awaiting an Action command.
	*
	* \return	Means if Instruction is registered.
	*/

	bool instructionRegistered();

	/*!
	* \fn	bool ofControlTable::moving();
	*
	* \brief	Get an indication if the Dynamixel is moving or not.
	*
	* \return	Means if there is any movement.
	*/

	bool moving();

	/*!
	* \fn	bool ofControlTable::EEPROMLocked();
	*
	* \brief	Locking EEPROM.
	*
	* \return	True if EEPROM is locked, false then.
	*/

	bool EEPROMLocked();

	/*!
	* \fn	int ofControlTable::punch();
	*
	* \brief	Get the punch value.
	*
	* \return	the punch value.
	*/

	int	punch();

	/*!
	* \fn	bool ofControlTable::enableTorque(bool torque);
	*
	* \brief	Enable the torque.
	*
	* \param	torque	The new value for torque state.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool enableTorque(bool torque);

	/*!
	* \fn	bool ofControlTable::setLed(int led);
	*
	* \brief	Set state of the LED.
	*
	* \param	led	The new value for the LED state.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setLed(int led);

	/*!
	* \fn	bool ofControlTable::setCWComplianceMargin(int CWComplianceMargin);
	*
	* \brief	Set the CW compliance margin.
	*
	* \param	CWComplianceMargin	The new walue for CW compliance margin.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setCWComplianceMargin(int CWComplianceMargin);

	/*!
	* \fn	bool ofControlTable::setCCWComplianceMargin(int CCWComplianceMargin);
	*
	* \brief	Set the CCW compliance margin.
	*
	* \param	CCWComplianceMargin	The new walue for CCW compliance margin.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setCCWComplianceMargin(int CCWComplianceMargin);

	/*!
	* \fn	bool ofControlTable::setCWComplianceSlope(int CWComplianceSlope);
	*
	* \brief	Set the CCW compliance slope.
	*
	* \param	CWComplianceSlope	The new walue for CCW compliance slope.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setCWComplianceSlope(int CWComplianceSlope);

	/*!
	* \fn	bool ofControlTable::setCCWComplianceSlope(int CCWComplianceSlope);
	*
	* \brief	Set the CCW compliance slope.
	*
	* \param	CCWComplianceSlope	The new walue for CCW compliance slope.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setCCWComplianceSlope(int CCWComplianceSlope);

	/*!
	* \fn	bool ofControlTable::setGoalPosition(int goalpostion);
	*
	* \brief	Set the goal position register.
	*
	* \param	goalpostion	The new goal position.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setGoalPosition(int goalpostion);

	/*!
	* \fn	bool ofControlTable::setMovingSpeed(int movingSpeed);
	*
	* \brief	Set the moving speed register.
	*
	* \param	movingSpeed	The new moving speed.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setMovingSpeed(int movingSpeed);

	/*!
	* \fn	bool ofControlTable::setTorqueLimit(int torqueLimit);
	*
	* \brief	Set the torque limit.
	*
	* \param	torqueLimit	The new torque limit.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool setTorqueLimit(int torqueLimit);

	/*!
	* \fn	bool ofControlTable::lockEEPROM();
	*
	* \brief	Lock the EEPROM memory.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool lockEEPROM();

	/*!
	* \fn	bool ofControlTable::unlockEEPROM();
	*
	* \brief	Unlock the EEPROM memory.
	*
	* \return	True if there is no error, false otherwise.
	*/

	bool unlockEEPROM();

	/*!
	* \fn	int ofControlTable::setPunch(int puch);
	*
	* \brief	Set the punch value.
	*
	* \param	puch	the new punch value.
	*
	* \return	True if there is no error, false otherwise.
	*/

	int	setPunch(int puch);

private:
	/*! \brief	The connexion */
	ofConnexion * connexion;
	/*! \brief	The identifier */
	int id;
	/*! \brief	The error */
	uint8_t error;
	/*! \brief	The data 1 byte */
	uint8_t data1Byte;
	/*! \brief	The data 2 byte */
	uint16_t data2Byte;

};
