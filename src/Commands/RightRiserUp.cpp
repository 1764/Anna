#include "RightRiserUp.h"

RightRiserUp::RightRiserUp()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void RightRiserUp::Initialize()
{
	right_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void RightRiserUp::Execute()
{
	right_riser->UsePIDOutput(0.6);
}

// Make this return true when this Command no longer needs to run execute()
bool RightRiserUp::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RightRiserUp::End()
{
	right_riser->UsePIDOutput(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RightRiserUp::Interrupted()
{
	right_riser->UsePIDOutput(0.0);
}
