/*!
 * \file	ofDynamixelException.h.
 *
 * \brief	Declares the of dynamixel exception class.
 */

#pragma once

#include <exception>
#include <iostream>

using namespace std;

/*!
 * \class	ofDynamixelException
 *
 * \brief	Exception for signalling of dynamixel errors.
 *
 * \author	Agh
 * \date	17/05/2017
 */

class ofDynamixelException
{
public:

	/*!
	 * \fn	ofDynamixelException::ofDynamixelException(const string &message = "") throw();
	 *
	 * \brief	Constructor.
	 *
	 * \param	message	(Optional) The exception message.
	 */

	ofDynamixelException(const string &message = "") throw();

	/*!
	 * \fn	virtual ofDynamixelException::~ofDynamixelException() throw();
	 *
	 * \brief	Destructor.
	 */

	virtual ~ofDynamixelException() throw();

	/*!
	 * \fn	virtual const char* ofDynamixelException::what() const throw();
	 *
	 * \brief	Gets the what. Display the message. 
	 *
	 * \return	Null if it fails, else the message explaining why this exception was launched.
	 */

	virtual const char* what() const throw();

private:
	/*! \brief	The message */
	string message;
};
