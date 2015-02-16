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
	oi->getGyro();
	double x = oi->getDriverJoystickX();
	double y = oi->getDriverJoystickY();
	double z = oi->getDriverJoystickZ();
	DriveWithJoystick::Thresh(x, 0.2);
    DriveWithJoystick::Thresh(y, 0.2);
	DriveWithJoystick::Thresh(z, 0.5);
	drive_train->SetMotor(x, y, z);
}

void DriveWithJoystick::Thresh(double a, double b)
{
	if(a > b)
		a -= b;
	else if(a < -b)
		a += b;
	else
		a = 0;
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
