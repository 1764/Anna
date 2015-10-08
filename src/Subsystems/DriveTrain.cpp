#include <Subsystems/DriveTrain.h>
#include <Victor.h>
#include "../Commands/DriveWithJoystick.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() :
		Subsystem("ExampleSubsystem")
{
	front_left_drive_motor = new Victor(FRONT_LEFT_DRIVE_MOTOR);
	front_right_drive_motor = new Victor(FRONT_RIGHT_DRIVE_MOTOR);
	back_left_drive_motor = new Victor(BACK_LEFT_DRIVE_MOTOR);
	back_right_drive_motor = new Victor(BACK_RIGHT_DRIVE_MOTOR);
}

void DriveTrain::SetMotor(double x, double y, double z)
{
	front_left_drive_motor->SetSpeed(x-y+z);
	front_right_drive_motor->SetSpeed(x+y+z);
	back_left_drive_motor->SetSpeed(-x-y+z);
	back_right_drive_motor->SetSpeed(-x+y+z);
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
