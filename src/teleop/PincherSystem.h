#include "WPILib.h"

#ifndef PINCHERSYSTEM_H
#define PINCHERSYSTEM_H

class PincherSystem {

	VictorSP *rightToteAccel;
	VictorSP *leftToteAccel;
	VictorSP *rightRollers;
	VictorSP *leftRollers;


	Solenoid *rightPincher;
	Solenoid *leftPincher;

	AnalogInput *topSensor;
	AnalogInput *bottomSensor;

	bool pinchersOpen;
	bool proxyTriggered;

	bool rightOpen;
	bool leftOpen;

public:


	PincherSystem();

	~PincherSystem();

	void OpenPinchers();
	void ClosePinchers();
	void TogglePinchers();
	void StopPinchers();

	void OpenRight();
	void OpenLeft();
	void CloseRight();
	void CloseLeft();

	bool TopProximityTriggered();
	bool BottomProximityTriggered();
	bool OpenState();

	void RunToteAccel();
	void RunPinchers();
	void RunRollers();
	void RunAt(float x);

	void ReverseToteAccel();
	void ReversePinchers();
	void ReverseRollers();
	void ReversePinchersSlow();

	void HumanLoad();

};

#endif