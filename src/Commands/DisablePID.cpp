#include "DisablePID.h"

DisablePID::DisablePID()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void DisablePID::Initialize()
{
	left_riser->Disable();
	right_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void DisablePID::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DisablePID::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void DisablePID::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DisablePID::Interrupted()
{

}
