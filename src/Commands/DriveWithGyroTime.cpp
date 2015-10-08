#include "DriveWithGyroTime.h"

DriveWithGyroTime::DriveWithGyroTime(double x, double y, double z, double time)
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
void DriveWithGyroTime::Initialize()
{
	this->SetTimeout(time);
}

// Called repeatedly when this Command is scheduled to run
void DriveWithGyroTime::Execute()
{
	double joystick_angle = atan2(x, y);
	double joystick_velocity = sqrt(x*x + y*y) * 0.75;
	double angle = joystick_angle - (oi->GetGyro() * 0.0174532925);
	drive_train->SetMotor(joystick_velocity*sin(-angle), joystick_velocity*cos(-angle), z);

}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithGyroTime::IsFinished()
{
	return this->IsTimedOut();
}

// Called once after isFinished returns true
void DriveWithGyroTime::End()
{
	drive_train->SetMotor(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithGyroTime::Interrupted()
{
	drive_train->SetMotor(0,0,0);
}
