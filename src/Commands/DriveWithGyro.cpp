#include "DriveWithGyro.h"
#include <cmath>
#include <iostream>
DriveWithGyro::DriveWithGyro()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive_train);
}

// Called just before this Command runs the first time
void DriveWithGyro::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void DriveWithGyro::Execute()
{
	std::cout << oi->GetGyro() << "\n";
	if(oi->getDriverJosytickButton(11))
	{
		oi->ResetGyro();
	}
	double input_x = -oi->getDriverJoystickX();
	double input_y = oi->getDriverJoystickY();
	double joystick_angle = atan2(input_x, input_y);
	double joystick_velocity = sqrt(input_x*input_x + input_y*input_y) * 0.75;
	double angle = joystick_angle - (oi->GetGyro() * 0.0174532925);

	if(oi->getDriverJosytickButton(1))
		drive_train->SetMotor(Thresh(oi->getDriverJoystickX(), 0.2), Thresh(oi->getDriverJoystickY(), 0.2), Thresh(oi->getDriverJoystickZ(), 0.5) * 2);
	else if(oi->getDriverJosytickButton(2))
		drive_train->SetMotor(Thresh(oi->getDriverJoystickX(), 0.2) * 0.5, Thresh(oi->getDriverJoystickY(), 0.2) * 0.5, Thresh(oi->getDriverJoystickZ(), 0.5));
	else
		drive_train->SetMotor(joystick_velocity*sin(-angle), joystick_velocity*cos(-angle), Thresh(oi->getDriverJoystickZ(), 0.5) * 1.5);
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

double DriveWithGyro::Thresh(double a, double b)
{
	if(a > b)
		a -= b;
	else if(a < -b)
		a += b;
	else
		a = 0;

	return a;
}
