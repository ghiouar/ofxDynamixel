#include "ofDynamixelException.h"


ofDynamixelException::ofDynamixelException(const string & message) throw()
{
	this->message = message;
}

ofDynamixelException::~ofDynamixelException()
{

}

const char * ofDynamixelException::what() const throw()
{
	return this->message.c_str();
}
