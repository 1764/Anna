#include "ResetLeftRiser.h"

ResetLeftRiser::ResetLeftRiser()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
}

// Called just before this Command runs the first time
void ResetLeftRiser::Initialize()
{
	left_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void ResetLeftRiser::Execute()
{
	left_riser->left_riser_motor->Set(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool ResetLeftRiser::IsFinished()
{
	return oi->getLeftLimit();
}

// Called once after isFinished returns true
void ResetLeftRiser::End()
{
	left_riser->left_riser_encoder->Reset();
	left_riser->left_riser_motor->Set(0);
	left_riser->Enable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetLeftRiser::Interrupted()
{
	left_riser->Enable();
	left_riser->left_riser_encoder->Reset();
	left_riser->left_riser_motor->Set(0);
}
