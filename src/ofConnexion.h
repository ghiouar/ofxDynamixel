/*!
 * \file	ofConnexion.h.
 * \brief	Declares the of connexion class.
 */

#pragma once
#include "dynamixel_sdk.h"

 /*!
  * \class	ofConnexion
  *
  * \brief	The ofConnexion class.
  *
  * \author	Abdessalam Ghiouar
  * \version 0.1
  * \date	April 25, 2017
  */

class ofConnexion
{
public:

	/*!
	 * \fn	ofConnexion::ofConnexion(const char * portName, float protocolVersion, int baudrate);
	 *
	 * \brief	Constructor of the ofConnexion class, Creates instance of ofConnexion.
	 *
	 * \param	portName	   	COM port device name.
	 * \param	protocolVersion	Version of the communication protocol used in Dynamixel.
	 * \param	baudrate	   	Baud Rate of Dynamixel.
	 */

	ofConnexion(const char * portName, float protocolVersion, int baudrate);

	/*!
	 * \fn	ofConnexion::ofConnexion();
	 *
	 * \brief	Constructor of the ofConnexion class, Creates instance of {@link ofConnexion}.
	 */

	ofConnexion();

	/*!
	 * \fn	ofConnexion::~ofConnexion();
	 *
	 * \brief	~ofConnexion.
	 *
	 */

	~ofConnexion();

	/*!
	 * \fn	bool ofConnexion::open();
	 *
	 * \brief	open open a connection with Dynamixel.
	 *
	 * \return	True if the connection is established, false otherwise.
	 */

	bool open();

	/*!
	 * \fn	void ofConnexion::close();
	 *
	 * \brief	close Close the connection already established with Dynamixel.
	 */

	void close();

	/*!
	 * \fn	void ofConnexion::connect(const char * portName, float protocolVersion, int baudrate);
	 *
	 * \brief	connect create a new connection with Dynamixel.
	 *
	 * \param	portName	   	COM port device name.
	 * \param	protocolVersion	Version of the communication protocol used in Dynamixel.
	 * \param	baudrate	   	Baud Rate of Dynamixel.
	 */

	void connect(const char * portName, float protocolVersion, int baudrate);

	/*!
	 * \fn	dynamixel::PortHandler * ofConnexion::getPortHandler();
	 *
	 * \brief	getPortHandler Get the port handler.
	 *
	 * \return	The port handler.
	 */

	dynamixel::PortHandler * getPortHandler();

	/*!
	 * \fn	dynamixel::PacketHandler * ofConnexion::getPacketHandler();
	 *
	 * \brief	getPacketHandler Get the packet handler.
	 *
	 * \return	The packet handler.
	 */

	dynamixel::PacketHandler * getPacketHandler();

	/*!
	 * \fn	int ofConnexion::getBaudRate();
	 *
	 * \brief	getBaudRate Get the  baud rate.
	 *
	 * \return	the baud rate.
	 */

	int getBaudRate();

	/*!
	 * \fn	bool ofConnexion::setBaudRate(int baudrate);
	 *
	 * \brief	setBaudRate Set the  baud rate.
	 *
	 * \param	baudrate	the  baud rate.
	 *
	 * \return	true if success set of the new baud rate.
	 */

	bool setBaudRate(int baudrate);

private:
	/*! \brief	The baudrate */
	int baudrate;
	/*! \brief	The port handler */
	dynamixel::PortHandler * portHandler;
	/*! \brief	The packet handler */
	dynamixel::PacketHandler *packetHandler;
};

