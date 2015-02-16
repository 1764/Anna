#include "DriveWithGyro.h"

DriveWithGyro::DriveWithGyro()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive_train);
}

// Called just before this Command runs the first time
void DriveWithGyro::Initialize()
{
	angle = 0;
}

// Called repeatedly when this Command is scheduled to run
void DriveWithGyro::Execute()
{
	angle = angle + oi->getDriverJoystickZ();
	double differ = oi->getGyro() - angle;
	if(differ > 45)
	{
		differ = 45;
	}
	if(differ < -45)
	{
		differ = -45;
	}
	double speed = (pow(differ, 3)*-0.000001)+(0.0144*differ);
	drive_train->SetMotor(0, 0, speed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithGyro::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithGyro::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithGyro::Interrupted()
{

}
