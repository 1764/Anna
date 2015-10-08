#include "ResetRisers.h"

ResetRisers::ResetRisers()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void ResetRisers::Initialize()
{
	left_riser->Disable();
	right_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void ResetRisers::Execute()
{
	if(!left_riser->getReset())
		left_riser->UsePIDOutput(-0.3);
	else
		left_riser->UsePIDOutput(0);

	if(!right_riser->getReset())
		right_riser->UsePIDOutput(-0.3);
	else
		right_riser->UsePIDOutput(0);
}

// Make this return true when this Command no longer needs to run execute()
bool ResetRisers::IsFinished()
{
	return left_riser && right_riser;
}

// Called once after isFinished returns true
void ResetRisers::End()
{
	left_riser->UsePIDOutput(0);
	right_riser->UsePIDOutput(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetRisers::Interrupted()
{
	left_riser->UsePIDOutput(0);
	right_riser->UsePIDOutput(0);
}
