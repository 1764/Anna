#include "DriveWithTime.h"

DriveWithTime::DriveWithTime(double x, double y, double z, double time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive_train);
	this->x = x;
	this->y = y;
	this->z = z;
	this->time = time;
}

// Called just before this Command runs the first time
void DriveWithTime::Initialize()
{
	this->SetTimeout(time);
}

// Called repeatedly when this Command is scheduled to run
void DriveWithTime::Execute()
{
	drive_train->SetMotor(x, y, z);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithTime::IsFinished()
{
	return this->IsTimedOut();
}

// Called once after isFinished returns true
void DriveWithTime::End()
{
	drive_train->SetMotor(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithTime::Interrupted()
{
	drive_train->SetMotor(0, 0, 0);
}
