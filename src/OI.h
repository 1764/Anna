#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *copilot_stick, *pilot_stick;
	DigitalInput *left_limit, *right_limit, *left_riser_limit, *right_riser_limit;
	JoystickButton *copilot_trigger, *pilot_trigger;
	AnalogInput *left_ultrasonic, *right_ultrasonic;
	Gyro *gyro;
public:
	OI();
	double getDriverJoystickX();
	double getDriverJoystickY();
	double getDriverJoystickZ();
	double getCopilotStickThrottle();
	bool getLeftLimit();
	bool getRightLimit();
	double getLeftUltrasonic();
	double getRightUltrasonic();
	double getGyro();
	bool getLeftRiserLimit();
	bool getRightRiserLimit();
};

#endif
