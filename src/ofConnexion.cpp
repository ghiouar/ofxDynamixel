#include "stdafx.h"
#include "ofConnexion.h"


ofConnexion::ofConnexion(const char * portName, float protocolVersion, int baudrate)
{

	baudrate = baudrate;
	portHandler = dynamixel::PortHandler::getPortHandler(portName);
	packetHandler = dynamixel::PacketHandler::getPacketHandler(protocolVersion);
}

ofConnexion::ofConnexion()
{
	baudrate = 0;
	portHandler = nullptr;
	packetHandler = nullptr;
}

ofConnexion::~ofConnexion()
{
	delete portHandler;
	delete packetHandler;
}


bool ofConnexion::open()
{
	return portHandler->openPort();
}

void ofConnexion::close()
{
	portHandler->closePort();
}

void ofConnexion::connect(const char * portName, float protocolVersion, int baud)
{
	baudrate = baud;
	portHandler = dynamixel::PortHandler::getPortHandler(portName);
	packetHandler = dynamixel::PacketHandler::getPacketHandler(protocolVersion);
	portHandler->openPort();
}

dynamixel::PortHandler * ofConnexion::getPortHandler()
{
	return portHandler;
}

dynamixel::PacketHandler * ofConnexion::getPacketHandler()
{
	return packetHandler;
}

bool ofConnexion::setBaudRate(int baudrate)
{
	return portHandler->setBaudRate(baudrate);
}
int ofConnexion::getBaudRate()
{
	return  portHandler->getBaudRate();
}

