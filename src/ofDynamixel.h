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
	 * \brief	getID.
	 *
	 * \return	The identifier.
	 */

	int getID();

	/*!
	 * \fn	char * ofDynamixel::getPortName();
	 *
	 * \brief	getDevince_name.
	 *
	 * \return	Null if it fails, else the port name.
	 */

	char * getPortName();

	/*!
	 * \fn	double ofDynamixel::getProtocolVersion();
	 *
	 * \brief	getProtocol_version.
	 *
	 * \return	The protocol version.
	 */

	double getProtocolVersion();

	/*!
	 * \fn	int ofDynamixel::getBaudrate();
	 *
	 * \brief	getBaudrate.
	 *
	 * \return	The baudrate.
	 */

	int getBaudrate();

	/*!
	 * \fn	int ofDynamixel::getPositionMinimum();
	 *
	 * \brief	getPosition_min.
	 *
	 * \return	The calculated position minimum.
	 */

	int getPositionMinimum();

	/*!
	 * \fn	int ofDynamixel::getPositionMaximum();
	 *
	 * \brief	getPosition_max.
	 *
	 * \return	The calculated position maximum.
	 */

	int getPositionMaximum();

	/*!
	 * \fn	int ofDynamixel::getTurnsCount();
	 *
	 * \brief	getTurns_count.
	 *
	 * \return	The turns count.
	 */

	int getTurnsCount();

	/*!
	 * \fn	ofControlTable * ofDynamixel::getControlTable();
	 *
	 * \brief	getControlTable.
	 *
	 * \return	Null if it fails, else the control table.
	 */

	ofControlTable * getControlTable();

	/*!
	 * \fn	ofConnexion * ofDynamixel::getPortHundler();
	 *
	 * \brief	getPortHundler.
	 *
	 * \return	Null if it fails, else the port handler.
	 */

	ofConnexion * getPortHandler();

	/*!
	 * \fn	void ofDynamixel::setID(int id);
	 *
	 * \brief	setID.
	 *
	 * \param	id	.
	 */

	void setID(int id);

	/*!
	 * \fn	void ofDynamixel::setPositionMinimum(int position_min);
	 *
	 * \brief	setPosition_min.
	 *
	 * \param	position_min	.
	 */

	void setPositionMinimum(int position_min);

	/*!
	 * \fn	void ofDynamixel::setPositionMaximum(int position_max);
	 *
	 * \brief	setPosition_max.
	 *
	 * \param	position_max	.
	 */

	void setPositionMaximum(int position_max);

	/*!
	 * \fn	void ofDynamixel::setTurnsCount(int turns_count);
	 *
	 * \brief	setTurns_count.
	 *
	 * \param	turns_count	.
	 */

	void setTurnsCount(int turns_count);

	/*!
	 * \fn	void ofDynamixel::setControlTable(ofControlTable * control_table);
	 *
	 * \brief	setControlTable.
	 *
	 * \param [in,out]	control_table	.
	 */

	void setControlTable(ofControlTable * control_table);

	/*!
	 * \fn	void ofDynamixel::setPortHundler(ofConnexion * portHundler);
	 *
	 * \brief	setPortHundler.
	 *
	 * \param [in,out]	portHundler	.
	 */

	void setPortHandler(ofConnexion * portHandler);

	/*!
	 * \fn	bool ofDynamixel::Ping();
	 *
	 * \brief	Pings this object.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool ping();

	/*!
	 * \fn	bool ofDynamixel::Reset();
	 *
	 * \brief	Resets this object.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Reset();

	/*!
	 * \fn	bool ofDynamixel::Initialize();
	 *
	 * \brief	Initializes this object.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Initialize();

	/*!
	 * \fn	bool ofDynamixel::Synchronize();
	 *
	 * \brief	Synchronizes this object.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Synchronize(); // delete ?

	/*!
	 * \fn	bool ofDynamixel::Stop();
	 *
	 * \brief	Stops this object.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	void Stop();

	/*!
	 * \fn	bool ofDynamixel::reboot();
	 *
	 * \brief	Reboots this object.
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool reboot();

	//ErrorStatus enum
	//	GetRegisterValue
	//		SetRegisterValue
	//		ReadAll


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
	/*! \brief	The port handler. */
	ofConnexion * portHandler;
	/*! \brief	The control table. */
	ofControlTable * controlTable;
	/*! \brief	The control table. */
	ofConnexion * connexionPort;


};


