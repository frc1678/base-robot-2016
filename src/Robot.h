

#ifndef ROBOT_H
#define ROBOT_H

//#include <logs/ConstantsLoader.h>
#include "WPILib.h"
//#include "logs/ConstantsLoader.h"
#include "teleop/CitrusButton.h"
#include "teleop/ElevatorSystem.h"
#include "teleop/Drivetrain.h"
#include "teleop/PincherSystem.h"
//#include <iostream>
//#include <fstream>
//#include <stdlib.h>

//using namespace std;

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "teleop/SteeringWheelDrive.h"
#include "logs/CSVLogger.h"
#include "logs/TextLogger.h"

using namespace std;


class Robot: public IterativeRobot
{

public:


	LiveWindow *lw;

	// Joysticks that Takumi drives with
	Joystick *driverL;
	Joystick *driverR;
	Joystick *manipulator;

	Joystick* steeringWheel;
	Joystick* speedJoystick;

	// For the driving of the robot
	RobotDrive *drivetrain;
	SteeringWheelDrive* swd;

	CSVLogger* CSVdriveLogger;
	TextLogger* driveLogger;

	// The elevator
	ElevatorSystem *elevator;

	Compressor *compressor;

	DoubleSolenoid *shifting;


	CitrusButton *gearUp;
	CitrusButton *gearDown;

	CitrusButton *deployedLeft;
	CitrusButton *deployedRight;
//
//	bool triggered3;
//	bool triggered4;

	CitrusButton *mag3;
	CitrusButton *mag4;
	CitrusButton *SteeringWheelChoice;

	PincherSystem *pinchers;




	//ConstantsLoader* kLoad;

	void RobotInit();

	void AutonomousInit();

	void AutonomousPeriodic();

	void TeleopInit();

	void TeleopPeriodic();

	void TestPeriodic();

	void DisabledInit();

	void DisabledPeriodic();

	void UpdateButtons();

	void logDrive(float leftEncoderVal, float rightEncoderVal, float REncoderRate, float LEncoderRate, double joy1, double joy2, float LeftMotorOutput, float RightMotorOutput);

	void CSVlogDrive(float LMotorOutput, float RMotorOutput, float LEncoderRate, float REncoderRate);
};

#endif