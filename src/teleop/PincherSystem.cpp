#include <teleop/PincherSystem.h>

/*
 *  Rolly grabbers  (pinchers)
	run in and reverse functions
	actuate pistons on the arms independently and together (plan for both)
	4 positions total
	Arms have to be out when the elevator moves
	Are assisting in tote pickup
	Rolly grabbers run until bottom proxy triggered
	Raise RC onto top fingers while driving to human player station
 *
 */

PincherSystem::PincherSystem() {

	rightToteAccel = new VictorSP(6); // TODO ports for all of these
	leftToteAccel = new VictorSP(3);
	rightRollers = new VictorSP(9);
	leftRollers = new VictorSP(0);


	// True = open
	// False = closed
	// NEEDS TO BE CONSISTANT THROUGHOUT
	rightPincher = new Solenoid(3); // TODO ports galore
	leftPincher = new Solenoid(4);

	topSensor = new AnalogInput(2);
	bottomSensor = new AnalogInput(1);

	pinchersOpen = false; // Could changed, depends on solenoid. However, this shouldn't change.
	rightOpen = false;
	leftOpen = false;

}

PincherSystem::~PincherSystem() { }



void PincherSystem::OpenPinchers() {
	pinchersOpen = true;
	rightPincher->Set(true);
	leftPincher->Set(true);
}

 void PincherSystem::ClosePinchers() {
	 pinchersOpen = false;
	 rightPincher->Set(false);
	 leftPincher->Set(false);
}

void PincherSystem::TogglePinchers() {
	pinchersOpen = !pinchersOpen;
	rightPincher->Set(pinchersOpen);
	leftPincher->Set(pinchersOpen);
}

void PincherSystem::OpenRight() {
	rightOpen = true;
	rightPincher->Set(true);
}

 void PincherSystem::OpenLeft() {
	 leftOpen = true;
	 leftPincher->Set(true);
}

void PincherSystem::CloseRight() {
	rightOpen = false;
	rightPincher->Set(false);
}

void PincherSystem::CloseLeft() {
	leftOpen = false;
	leftPincher->Set(false);
}

// http://wpilib.screenstepslive.com/s/4485/m/13810/l/241876-analog-inputs
bool PincherSystem::TopProximityTriggered() {
	if (topSensor->GetValue() < 1000){ //TODO change based on how close we want the tote
		return true;
	}
	else {
		return false;
	}
}

bool PincherSystem::BottomProximityTriggered() {
	if(bottomSensor->GetValue() < 1000) {
		return true;
	}
	else {
		return false;
	}
}

bool PincherSystem::OpenState(){
	return pinchersOpen;
}

void PincherSystem::RunPinchers() {
	rightRollers->Set(1.0);
	leftRollers->Set(1.0);
	rightToteAccel->Set(1.0);
	leftToteAccel->Set(1.0);
}

void PincherSystem::RunToteAccel() {
	rightToteAccel->Set(1.0);
	leftToteAccel->Set(1.0);
}

void PincherSystem::RunRollers() {
	rightRollers->Set(1.0);
	leftRollers->Set(1.0);
}

void PincherSystem::RunAt(float x){
	rightRollers->Set(x);
	leftRollers->Set(x);
	rightToteAccel->Set(x);
	leftToteAccel->Set(x);
}


void PincherSystem::ReversePinchers() {
	rightRollers->Set(1.0);
	leftRollers->Set(1.0);
	rightToteAccel->Set(1.0);
	leftToteAccel->Set(1.0);
}

void PincherSystem::ReverseToteAccel() {
	rightToteAccel->Set(1.0);
	leftToteAccel->Set(1.0);
}

void PincherSystem::ReverseRollers() {
	rightRollers->Set(-1.0);
	leftRollers->Set(-1.0);
}

void PincherSystem::ReversePinchersSlow() {
	rightRollers->Set(0.2);
	leftRollers->Set(0.2);
}

void PincherSystem::HumanLoad() {

	if (BottomProximityTriggered()) {
		RunToteAccel();
	}
	else {
		RunPinchers();
	}

	if(!pinchersOpen){
		ClosePinchers();
	}
}

void PincherSystem::StopPinchers() {
	rightRollers->Set(0.0);
	leftRollers->Set(0.0);
	rightToteAccel->Set(0.0);
	leftToteAccel->Set(0.0);

}
