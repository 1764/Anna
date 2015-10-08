#include "LeftRiserUp.h"

LeftRiserUp::LeftRiserUp()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
}

// Called just before this Command runs the first time
void LeftRiserUp::Initialize()
{
	left_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void LeftRiserUp::Execute()
{
	left_riser->UsePIDOutput(0.6);
}

// Make this return true when this Command no longer needs to run execute()
bool LeftRiserUp::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LeftRiserUp::End()
{
	left_riser->UsePIDOutput(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LeftRiserUp::Interrupted()
{
	left_riser->UsePIDOutput(0);
}
