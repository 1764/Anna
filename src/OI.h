#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *driver_joystick, *copilot_joystick;
	JoystickButton *riser_reset_button;
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
};

#endif
