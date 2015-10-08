#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive_train);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{
	if(oi->getDriverJosytickButton(2))
		drive_train->SetMotor(Thresh(oi->getDriverJoystickX(), 0.2) * 0.5, Thresh(oi->getDriverJoystickY(), 0.2) * 0.5, Thresh(oi->getDriverJoystickZ(), 0.5) * 0.9);
	else
		drive_train->SetMotor(Thresh(oi->getDriverJoystickX(), 0.2), Thresh(oi->getDriverJoystickY(), 0.2), Thresh(oi->getDriverJoystickZ(), 0.5) * 1.9);

}

double DriveWithJoystick::Thresh(double a, double b)
{
	if(a > b)
		a -= b;
	else if(a < -b)
		a += b;
	else
		a = 0;

	return a;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted()
{

}
