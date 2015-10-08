#include "RightRiserDown.h"

RightRiserDown::RightRiserDown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void RightRiserDown::Initialize()
{
	right_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void RightRiserDown::Execute()
{
	right_riser->UsePIDOutput(-0.3);
}

// Make this return true when this Command no longer needs to run execute()
bool RightRiserDown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RightRiserDown::End()
{
	right_riser->UsePIDOutput(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RightRiserDown::Interrupted()
{
	right_riser->UsePIDOutput(0.0);
}
