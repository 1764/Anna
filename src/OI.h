#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *driver_joystick, *copilot_joystick;
	JoystickButton *raise_button, *lower_button, *left_up_button, *left_down_button, *right_up_button, *right_down_button, *reset_button, *enable_button, *disable_button;
	Gyro *gyro;
public:
	OI();
	double getDriverJoystickX();
	double getDriverJoystickY();
	double getDriverJoystickZ();
	double getCopilotThrottle();
	bool getDriverJosytickButton(int);
	bool getCopilotJoystickButton(int);
	bool getReset();
	double a();
	double GetGyro();
	void ResetGyro();
};

#endif
