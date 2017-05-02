OfxDynamixel 
=====================================

OpenFrameworks addon for controlling and interacting Dynamixel Robotis Actuator from Robotis.


Description
------------
OfxDynamixel is an openframeworks (Ofx) library / addon that allows you to control Dynamixel Robotis Actuator. OfxDynamixel is written in C ++ to meet the requirements of openframeworks. This addon uses DynamixelSDK library which can be found at https://github.com/ROBOTIS-GIT/DynamixelSDK. 

The ROBOTIS Dynamixel SDK is a software development library that provides Dynamixel control functions for packet communication. The API is designed for Dynamixel actuators and Dynamixel-based platforms.

OfxDynamixel allows to read and modify the data of the control table. The Dynamixel servomotors are controlled by modifying these data as for example the position, led satet, Id ...

For the moment, we can create a connection with dynamixel servos by using the class ofConnexion.
We can read and modify all the registers of the control table. The methods of class ofControleTable offer this possibility. Almost all registers can be read and modified without incident.
OfxDynamixel is contains the following class :

- ofConnexion : Create a connection with the Dynamixel actuators by using the methods of the DynamixelSDK library which. You must provide device name (COM), boudrate, and the protocol version to create a connection.
- ofControleTable : provides the necessary methods for reading and modifying the registers of the control table.

The Development of the ofxDynamixel class is in progress. this class is the global class to communicate with the Dynamxel Servos. this class contains instances ofConnection ofControleTable and other methods such as reboot, stop, reset, ping.

Installation
------------
You must copy the addon folder of ofxDynamixel to the folder of_vx.x.x_vs_release / addons and create an openframworks project by choosing ofxDynamixel in "Community addons"

Dependencies
------------
This addon does not depend on any other addon to work properly

Compatibility
------------
This addon is compatible with version 0.9.8 of OpenFrameworks (of v0.9.8_vs_release)

License
-------
The code in this repository is available under the [MIT License](https://secure.wikimedia.org/wikipedia/en/wiki/Mit_license). Copyright (c) [April 2017] [Abdessalam Ghiouar], See lience.md

Known issues
------------
April 25, 2017	: Development of the Dynamixel class is in progress

Version history
------------
### Version 0.1 (April, 25 2017):
In this version, we can now create a connection with dynamixel servos by using the class ofConnexion.
We can read and modify all the registers of the control table. The methods of class ofControleTable offer this possibility. Almost all registers can be read and modified without incident.


