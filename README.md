OfxDynamixel 
=====================================

OpenFrameworks addon for controlling and interacting Dynamixel Robotis Actuator from Robotis.


Description
------------
OfxDynamixel is an openframeworks (Ofx) addon that allows you to control Dynamixel Robotis Actuator. OfxDynamixel  is built on top of C++ to meet the requirements of openframeworks. This addon uses DynamixelSDK library which can be found at https://github.com/ROBOTIS-GIT/DynamixelSDK. 
The ROBOTIS Dynamixel SDK is a software development library that provides Dynamixel control functions for packet communication. The API is designed for Dynamixel actuators and Dynamixel-based platforms.

The ofxDynamixel addon allows to do all the necessary basic operations on a Dynamixel servomotor. The classes provided allow easy communication with Dynamxiel and are easy to use. 
OfxDynamixel allows to read and modify the data of the control table. The Dynamixel servomotors are controlled by modifying these data as for example the position, led satet, Id ...

Three main classes have been developed:


* The class ofConnection
    Create a connection with the Dynamixel actuators by using the methods of the DynamixelSDK library. You must provide port name , boudrate, and the protocol version.

* The class ofContorolTable 
This class allows to read and modify the information contained in the Dynamixel control table such as ID, position, speed, temperature, etc. 

* The class ofDynamixel 
    OfDynamixel is the main class that groups the previous two classes. This class also provides methods for checking the operation of the servo motors by ping, resetting, stopping, and restarting the servo motors. 
    It also allows the Dynamixel actuators to be positioned at a given position and speed. 

Features
------------
ofxDynamixel offers the following features :
* Create a communication with dynamixel.
* Read and update the registers of the control table.
* Ping, reboot, reset, stop the dynamixels.
* Move to a position with a moving speed.


Installation
------------
ofxDynamixel offers the following features :
1. Clone or download this repository into your openFrameworks/addons directory. 
2. Create a new openframworks project using project generator or openFrameworks plugin for visual studio.
3. Choose ofxDynamixel in "Addons" for project generator or in "Community addons" for visual studio plugin.
4. Add ofDynamixel to your project by adding ``` #include "ofDynamixel.h" ``` to the top of your ofApp.h file.

Ofx Dynamixel requires Dynamixel SDK to work properly, you must configure the project to integrate the Dynamixel SDK library : 
1. Open project properties. 
2. Add path in Debugging-Environment tab as shown below 
```
PATH=%PATH%;..\..\..\..\..\build\win32\output;
```
3. Add path in VC++-Library Directories tab 
```
..\..\..\libs\DynamixelSDK\build\win32\output\
```
4. Add path in C/C++-Common-Additional include directory tab
```
..\..\..\libs\DynamixelSDK\include\
```
5. Add file name in Linker-Input-Additional dependency tab 
```
dxl_x86_cpp.lib;
```
    

Dependencies
------------
This addon does not depend on any other addon to work properly.

Compatibility
------------
This addon is compatible with version 0.9.8 of OpenFrameworks (of v0.9.8_vs_release)

License
-------
The code in this repository is available under the [MIT License](https://secure.wikimedia.org/wikipedia/en/wiki/Mit_license). Copyright (c) [June 2017] [Abdessalam Ghiouar], See lience.md

Version history
------------
#####  Version 1.0 (June, 20 2017):
This first version gives us the posiibilty to easily communicate with dynamixels in a openframworks project.
All  basic operations such as the verification, modification and reading of the data of the dynamixels can be performed without incident.

Known issues
------------
If you notice any issues, please report them [here](https://github.com/ghiouar/OfxDynamixel/issues).


