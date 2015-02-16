#include "OI.h"
#include "RobotMap.h"
#include "Commands/ResetLifters.h"

OI::OI()
{
	driver_joystick = new Joystick(DRIVER_JOYSTICK_PORT);
	copilot_joystick = new Joystick(COPILOT_JOYSTICK_PORT);
}

double OI::getDriverJoystickX()
{
	return driver_joystick->GetX();
}

double OI::getDriverJoystickY()
{
	return driver_joystick->GetY();
}

double OI::getDriverJoystickZ()
{
	return driver_joystick->GetThrottle();
}

double OI::getCopilotThrottle()
{
	return copilot_joystick->GetZ();
}

bool OI::getReset()
{
	return copilot_joystick->GetTrigger();
}

bool OI::getDriverJosytickButton(int i)
{
	return driver_joystick->GetRawButton(i);
}

bool OI::getCopilotJoystickButton(int i)
{
	return copilot_joystick->GetRawButton(i);
}

double OI::a()
{
	return copilot_joystick->GetZ();
}
