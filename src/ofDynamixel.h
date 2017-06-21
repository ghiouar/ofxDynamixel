/*!
 * \file	ofDynamixel.h.
 * \brief	Declares the of dynamixel class.
 */

#pragma once

#include "ofControlTable.h"
#include "ofConnexion.h"

 /*!
  * \class	ofDynamixel
  *
  * \brief	An of dynamixel. Global class for a Dynamixel servo.
  *
  * \author	Abdessalam Ghiouar \version	0.1
  * \date	April 25, 2017
  */

class ofDynamixel
{
public:

	/*!
	* \fn	ofDynamixel::ofDynamixel(int id, ofConnexion * portHandler, int position_min, int position_max);
	*
	* \brief	Constructor of the ofControlTable class, Creates instance of ofControlTable.
	*
	* \param 		  	id			   	The Dynamixel ID.
	* \param 		  	portHandler		The port Handler.
	* \param 		  	positionMin	   	position Minimum limit.
	* \param 		  	positionMax	   	position Maximum limit.
	*/
	ofDynamixel(int id, ofConnexion * portHandler, int position_min, int position_max);

	/*!
	 * \fn	ofDynamixel::ofDynamixel(int id, char * portName, double protocolVersion, int baudrate, int positionMin, int positionMax);
	 *
	 * \brief	Constructor of the ofControlTable class, Creates instance of ofControlTable.
	 *
	 * \param 		  	id			   	The Dynamixel ID.
	 * \param [in,out]	portName	   	COM port device name.
	 * \param 		  	protocolVersion	Version of the communication protocol used in Dynamixel.
	 * \param 		  	baudrate	   	Baud Rate of Dynamixel.
	 * \param 		  	positionMin	   	position Minimum limit.
	 * \param 		  	positionMax	   	position Maximum limit.
	 */

	ofDynamixel(int id, char * portName, float protocolVersion, int baudrate, int positionMin, int positionMax);

	/*!
	 * \fn	ofDynamixel::ofDynamixel(int id, char * device_name, double protocol_version, int baudrate);
	 *
	 * \brief	Constructor of the ofControlTable class, Creates instance of ofControlTable.
	 *
	 * \param 		  	id					The Dynamixel ID.
	 * \param [in,out]	device_name			COM port device name.
	 * \param 		  	protocol_version	Version of the communication protocol used in Dynamixel.
	 * \param 		  	baudrate			Baud Rate of Dynamixel.
	 */

	ofDynamixel(int id, char * device_name, float protocol_version, int baudrate);

	/*!
	 * \fn	ofDynamixel::ofDynamixel(int id, int positon_min, int position_max);
	 *
	 * \brief	Constructor of the ofControlTable class, Creates instance of ofControlTable.
	 *
	 * \param	id				The Dynamixel ID.
	 * \param	positon_min 	position Minimum limit.
	 * \param	position_max	position Maximum limit.
	 */

	ofDynamixel(int id, int positon_min, int position_max);

	/*!
	 * \fn	ofDynamixel::ofDynamixel(int id);
	 *
	 * \brief	Constructor of the ofControlTable class, Creates instance of ofControlTable.
	 *
	 * \param	id	The Dynamixel ID.
	 */

	ofDynamixel(int id);

	/*!
	 * \fn	ofDynamixel::~ofDynamixel();
	 *
	 * \brief	ofDynamixel.
	 */

	~ofDynamixel();

	/*!
	 * \fn	int ofDynamixel::getID();
	 *
	 * \brief	Get the Dynamixel ID.
	 *
	 * \return	The identifier.
	 */

	int getID();

	/*!
	 * \fn	char * ofDynamixel::getPortName();
	 *
	 * \brief	Get Port name.
	 *
	 * \return	Null if it fails, else the port name.
	 */

	char * getPortName();

	/*!
	 * \fn	double ofDynamixel::getProtocolVersion();
	 *
	 * \brief	Get the protocol version.
	 *
	 * \return	The protocol version.
	 */

	double getProtocolVersion();

	/*!
	 * \fn	int ofDynamixel::getBaudrate();
	 *
	 * \brief	get the baudrate.
	 *
	 * \return	The baudrate.
	 */

	int getBaudrate();

	/*!
	 * \fn	int ofDynamixel::getPositionMinimum();
	 *
	 * \brief	Get the position minimum.
	 *
	 * \return	The calculated position minimum.
	 */

	int getPositionMinimum();

	/*!
	 * \fn	int ofDynamixel::getPositionMaximum();
	 *
	 * \brief	Get the position maximum.
	 *
	 * \return	The calculated position maximum.
	 */

	int getPositionMaximum();

	/*!
	 * \fn	int ofDynamixel::getTurnsCount();
	 *
	 * \brief	Get the turns count.
	 *
	 * \return	The turns count.
	 */

	int getTurnsCount();

	/*!
	 * \fn	ofControlTable * ofDynamixel::getControlTable();
	 *
	 * \brief	Get the the control table.
	 *
	 * \return	Null if it fails, else the control table.
	 */

	ofControlTable * getControlTable();

	/*!
	 * \fn	ofConnexion * ofDynamixel::getPortHundler();
	 *
	 * \brief	Get the port handler.
	 *
	 * \return	Null if it fails, else the port handler.
	 */
	ofConnexion * getPortHandler();


	/*!
	 * \fn	void ofDynamixel::setID(int id);
	 *
	 * \brief	Set the Dynamixel ID.
	 *
	 * \param	The new Dynamixel ID..
	 */

	void setID(int id);

	/*!
	 * \fn	void ofDynamixel::setPositionMinimum(int positionMin);
	 *
	 * \brief	Set position min value.
	 *
	 * \param	The new position min.
	 */

	void setPositionMinimum(int positionMin);

	/*!
	 * \fn	void ofDynamixel::setPositionMaximum(int positionMax);
	 *
	 * \brief	Set position max value.
	 *
	 * \param	The new position max.	.
	 */

	void setPositionMaximum(int positionMax);

	/*!
	 * \fn	void ofDynamixel::setTurnsCount(int turns_count);
	 *
	 * \brief	Set turns count value.
	 *
	 * \param	The new	turns count value.
	 */

	void setTurnsCount(int turnsCount);

	/*!
	 * \fn	void ofDynamixel::setControlTable(ofControlTable * control_table);
	 *
	 * \brief	Set the control table object.
	 *
	 * \param [in,out]	The new control table object.
	 */

	void setControlTable(ofControlTable * controlTable);

	/*!
	 * \fn	void ofDynamixel::setPortHundler(ofConnexion * portHundler);
	 *
	 * \brief	Set the port handler.
	 *
	 * \param [in,out]	The new port hundler.	.
	 */

	void setPortHandler(ofConnexion * portHandler);

	/*!
	 * \fn	bool ofDynamixel::Ping();
	 *
	 * \brief	Ping the Dynamixel servo.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool ping();

	/*!
	 * \fn	bool ofDynamixel::Reset();
	 *
	 * \brief	Reset the Dynamixel servo.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Reset();

	/*!
	 * \fn	bool ofDynamixel::Initialize();
	 *
	 * \brief	Initialize the Dynamixel servo.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Initialize();


	/*!
	 * \fn	bool ofDynamixel::Stop();
	 *
	 * \brief	Stop the Dynamixel servo.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	void Stop();

	/*!
	 * \fn	bool ofDynamixel::reboot();
	 *
	 * \brief	Reboots the Dynamixel servo.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool reboot();
	
	/*!
	 * \fn	bool move(int goalPosition, int movingSpeed = -1);
	 *
	 * \brief	Moving to a goal position with a moving speed.
	 * \param 		  	goalPosition	goal position.
	 * \param 		  	movingSpeed	   	moving speed.
	 *
	 * \return	True if succes, false if it fails.
	 */
	bool move(int goalPosition, int movingSpeed = -1);
	
	/*!
	 * \fn	void moveWithAcceleration(int goalPosition, int movingSpeed, int accelerationSpeed);
	 *
	 * \brief	Moving to a goal position with a moving speed and a acceleration.
	 * \param 		  	goalPosition		Goal position.
	 * \param 		  	movingSpeed	   		Moving speed.
	 * \param 			accelerationSpeed	Acceleration.
	 * \return	True if succes, false if it fails.
	 */
	void moveWithAcceleration(int goalPosition, int movingSpeed, int accelerationSpeed);


private:
	/*! \brief	The identifier. */
	int id;
	/*! \brief	Name of the device. */
	char * portName;
	/*! \brief	The protocol version. */
	float protocolVersion;
	/*! \brief	The baudrate. */
	int baudrate;
	/*! \brief	The position minimum. */
	int positionMinimum;
	/*! \brief	The position maximum. */
	int positionMaximum;
	/*! \brief	Number of turns. */
	int turnsCount;
	/*! \brief	The control table. */
	ofControlTable * controlTable;
	/*! \brief	The control table. */
	ofConnexion * portHandler;


};


