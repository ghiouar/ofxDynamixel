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
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param 		  	id			   	The Dynamixel ID.
	 * \param [in,out]	portName	   	COM port device name.
	 * \param 		  	protocolVersion	Version of the communication protocol used in Dynamixel.
	 * \param 		  	baudrate	   	Baud Rate of Dynamixel.
	 * \param 		  	positionMin	   	position Minimum limit.
	 * \param 		  	positionMax	   	position Maximum limit.
	 */

	ofDynamixel(int id, char * portName, double protocolVersion, int baudrate, int positionMin, int positionMax);

	/*!
	 * \fn	ofDynamixel::ofDynamixel(int id, char * device_name, double protocol_version, int baudrate);
	 *
	 * \brief	Constructor of the ofControlTable class, Creates instance of ofControlTable.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param 		  	id					The Dynamixel ID.
	 * \param [in,out]	device_name			COM port device name.
	 * \param 		  	protocol_version	Version of the communication protocol used in Dynamixel.
	 * \param 		  	baudrate			Baud Rate of Dynamixel.
	 */

	ofDynamixel(int id, char * device_name, double protocol_version, int baudrate);

	/*!
	 * \fn	ofDynamixel::ofDynamixel(int id, int positon_min, int position_max);
	 *
	 * \brief	Constructor of the ofControlTable class, Creates instance of ofControlTable.
	 *
	 * \author	Agh
	 * \date	01/05/2017
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
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param	id	The Dynamixel ID.
	 */

	ofDynamixel(int id);

	/*!
	 * \fn	ofDynamixel::~ofDynamixel();
	 *
	 * \brief	ofDynamixel.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 */

	~ofDynamixel();

	/*!
	 * \fn	int ofDynamixel::getID();
	 *
	 * \brief	getID.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	The identifier.
	 */

	int getID();

	/*!
	 * \fn	char * ofDynamixel::getPortName();
	 *
	 * \brief	getDevince_name.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	Null if it fails, else the port name.
	 */

	char * getPortName();

	/*!
	 * \fn	double ofDynamixel::getProtocolVersion();
	 *
	 * \brief	getProtocol_version.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	The protocol version.
	 */

	double getProtocolVersion();

	/*!
	 * \fn	int ofDynamixel::getBaudrate();
	 *
	 * \brief	getBaudrate.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	The baudrate.
	 */

	int getBaudrate();

	/*!
	 * \fn	int ofDynamixel::getPositionMinimum();
	 *
	 * \brief	getPosition_min.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	The calculated position minimum.
	 */

	int getPositionMinimum();

	/*!
	 * \fn	int ofDynamixel::getPositionMaximum();
	 *
	 * \brief	getPosition_max.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	The calculated position maximum.
	 */

	int getPositionMaximum();

	/*!
	 * \fn	int ofDynamixel::getTurnsCount();
	 *
	 * \brief	getTurns_count.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	The turns count.
	 */

	int getTurnsCount();

	/*!
	 * \fn	ofControlTable * ofDynamixel::getControlTable();
	 *
	 * \brief	getControlTable.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	Null if it fails, else the control table.
	 */

	ofControlTable * getControlTable();

	/*!
	 * \fn	ofConnexion * ofDynamixel::getPortHundler();
	 *
	 * \brief	getPortHundler.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	Null if it fails, else the port hundler.
	 */

	ofConnexion * getPortHundler();

	/*!
	 * \fn	void ofDynamixel::setID(int id);
	 *
	 * \brief	setID.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param	id	.
	 */

	void setID(int id);

	/*!
	 * \fn	void ofDynamixel::setPositionMinimum(int position_min);
	 *
	 * \brief	setPosition_min.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param	position_min	.
	 */

	void setPositionMinimum(int position_min);

	/*!
	 * \fn	void ofDynamixel::setPositionMaximum(int position_max);
	 *
	 * \brief	setPosition_max.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param	position_max	.
	 */

	void setPositionMaximum(int position_max);

	/*!
	 * \fn	void ofDynamixel::setTurnsCount(int turns_count);
	 *
	 * \brief	setTurns_count.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param	turns_count	.
	 */

	void setTurnsCount(int turns_count);

	/*!
	 * \fn	void ofDynamixel::setControlTable(ofControlTable * control_table);
	 *
	 * \brief	setControlTable.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param [in,out]	control_table	.
	 */

	void setControlTable(ofControlTable * control_table);

	/*!
	 * \fn	void ofDynamixel::setPortHundler(ofConnexion * portHundler);
	 *
	 * \brief	setPortHundler.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \param [in,out]	portHundler	.
	 */

	void setPortHundler(ofConnexion * portHundler);

	/*!
	 * \fn	bool ofDynamixel::Ping();
	 *
	 * \brief	Pings this object.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool ping();

	/*!
	 * \fn	bool ofDynamixel::Reset();
	 *
	 * \brief	Resets this object.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Reset();

	/*!
	 * \fn	bool ofDynamixel::Initialize();
	 *
	 * \brief	Initializes this object.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Initialize();

	/*!
	 * \fn	bool ofDynamixel::Synchronize();
	 *
	 * \brief	Synchronizes this object.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Synchronize(); // delete ?

	/*!
	 * \fn	bool ofDynamixel::scanServos();
	 *
	 * \brief	Scans the servos.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool scanServos(); // depalce

	/*!
	 * \fn	bool ofDynamixel::Stop();
	 *
	 * \brief	Stops this object.
	 *
	 * \author	Agh
	 * \date	01/05/2017
	 *
	 * \return	True if it succeeds, false if it fails.
	 */

	bool Stop();

	/*!
	 * \fn	bool ofDynamixel::reboot();
	 *
	 * \brief	Reboots this object.
	 *
	 * \author	Agh
	 * \date	01/05/2017
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
	double protocolVersion;
	/*! \brief	The baudrate. */
	int baudrate;
	/*! \brief	The position minimum. */
	int positionMinimum;
	/*! \brief	The position maximum. */
	int positionMaximum;
	/*! \brief	Number of turns. */
	int turnsCount;
	/*! \brief	The port hundler. */
	ofConnexion * portHundler;
	/*! \brief	The control table. */
	ofControlTable * control_table;


};


