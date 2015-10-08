#include "OI.h"
#include "RobotMap.h"
#include "Commands/MoveRisersUp.h"
#include "Commands/MoveRisersDown.h"
#include "Commands/LeftRiserUp.h"
#include "Commands/LeftRiserDown.h"
#include "Commands/RightRiserUp.h"
#include "Commands/RightRiserDown.h"
#include "Commands/ResetRisers.h"
#include "Commands/EnablePID.h"
#include "Commands/DisablePID.h"

OI::OI()
{
	driver_joystick = new Joystick(DRIVER_JOYSTICK_PORT);
	copilot_joystick = new Joystick(COPILOT_JOYSTICK_PORT);
	raise_button = new JoystickButton(copilot_joystick, 8);
	  raise_button->WhileHeld(new MoveRisersUp());
	lower_button = new JoystickButton(copilot_joystick, 9);
	  lower_button->WhileHeld(new MoveRisersDown());

	left_up_button = new JoystickButton(copilot_joystick, 6);
	  left_up_button->WhileHeld(new LeftRiserUp());
	left_down_button = new JoystickButton(copilot_joystick, 7);
	  left_down_button->WhileHeld(new LeftRiserDown());

	right_up_button = new JoystickButton(copilot_joystick, 11);
	  right_up_button->WhileHeld(new RightRiserUp());
	right_down_button = new JoystickButton(copilot_joystick, 10);
	  right_down_button->WhileHeld(new RightRiserDown());

	reset_button = new JoystickButton(copilot_joystick, 1);
	  reset_button->WhileHeld(new ResetRisers());

	enable_button = new JoystickButton(copilot_joystick, 3);
	  enable_button->WhenPressed(new EnablePID());
	disable_button = new JoystickButton(copilot_joystick, 2);
	  disable_button->WhenPressed(new DisablePID());

	gyro = new Gyro(GYRO_PORT);

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
	return driver_joystick->GetZ();
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

double OI::GetGyro()
{
	SmartDashboard::PutNumber("Gyro", gyro->GetAngle());
	return gyro->GetAngle();
}

void OI::ResetGyro()
{
	gyro->Reset();
}
