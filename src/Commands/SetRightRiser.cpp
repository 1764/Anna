#include "SetRightRiser.h"

SetRightRiser::SetRightRiser()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis); Bobby was not here
	Requires(right_riser);
}

// Called just before this Command runs the first time
void SetRightRiser::Initialize()
{
	//right_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void SetRightRiser::Execute()
{

	right_riser->SetSetpoint((oi->getCopilotStickThrottle()-1) * 1190);
	//right_riser->right_riser_motor->Set(oi->getCopilotStickThrottle());
}

// Make this return true when this Command no longer needs to run execute()
bool SetRightRiser::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SetRightRiser::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetRightRiser::Interrupted()
{

}
