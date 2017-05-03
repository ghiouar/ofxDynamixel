/*!
 * \file	ofRegister.h
 *
 * \brief	Declares the of registry class.
*/

#pragma once

#include <inttypes.h>

/*!
 * \enum	ofRegister enum
 *
 * \brief	Values that represent of registries.
 *
 * \author  Abdessalam Ghiouar
 * \version 0.1
 * \date	April 25, 2017
 */

enum class ofRegister : uint16_t
{
	MODEL_NUMBER = 0,
	VERSION_FIRMWARE = 2,
	ID = 3,
	BAUD_RATE = 4,
	RETURN_DELAY_TIME = 5,
	CW_ANGLE_LIMIT = 6,
	CCW_ANGLE_LIMIT = 8,
	TEMPERATURE_LIMIT = 11,
	VOLTAGE_LIMIT_LOW = 12,
	VOLTAGE_LIMIT_HIGH = 13,
	MAX_TORQUE = 14,
	STATUS_RETURN_LEVEL = 16,
	ALARM_LED = 17,
	ALARM_SHUTDOWN = 18,
	TORQUE_ENABLE = 24,
	LED = 25,
	CW_COMPLIANCE_MARGIN = 26,
	CCW_COMPLIANCE_MARGIN = 27,
	CW_COMPLIANCE_SLOPE = 28,
	CCW_COMPLIANCE_SLOPE = 29,
	GOAL_POSITION = 30,
	MOVING_SPEED = 32,
	TORQUE_LIMIT = 34,
	PRESENT_POSITION = 36,
	PRESENT_SPEED = 38,
	PRESENT_LOAD = 40,
	PRESENT_VOLTAGE = 42,
	PRESENT_TEMPERATURE = 43,
	REDG = 44,
	MOVING = 46,
	LOCKEEPROM = 47,
	PUNCH = 48,
	GOAL_ACCELERATION = 49,
};

