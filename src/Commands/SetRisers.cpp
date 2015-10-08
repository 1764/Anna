#include "SetRisers.h"

SetRisers::SetRisers(int target)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
	Requires(right_riser);
	target_ = target;
}

// Called just before this Command runs the first time
void SetRisers::Initialize()
{
	left_riser->Enable();
	right_riser->Enable();
}

// Called repeatedly when this Command is scheduled to run
void SetRisers::Execute()
{
	left_riser->SetSetpoint(target_);
	right_riser->SetSetpoint(target_);
}

// Make this return true when this Command no longer needs to run execute()
bool SetRisers::IsFinished()
{
	return abs(left_riser->GetPosition() - target_) < 20 && abs(right_riser->GetPosition() - target_) < 20;
}

// Called once after isFinished returns true
void SetRisers::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetRisers::Interrupted()
{

}
