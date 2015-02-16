#include "ResetRightRiser.h"


ResetRightRiser::ResetRightRiser()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void ResetRightRiser::Initialize()
{
	std::cout << "Resetting  Right Riser!" << "\n";
	right_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void ResetRightRiser::Execute()
{
	//right_riser->SetSetpoint((oi->getCopilotStickThrottle()-1) * 1190);
	//std::cout << "Moving Down" << "\n";
	right_riser->right_riser_motor->Set(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool ResetRightRiser::IsFinished()
{

	return oi->getRightLimit();
}

// Called once after isFinished returns true
void ResetRightRiser::End()
{
	std::cout << "Tis Over." << "\n";
	right_riser->right_riser_encoder->Reset();
	right_riser->right_riser_motor->Set(0);
	right_riser->Enable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetRightRiser::Interrupted()
{
	right_riser->Enable();
	right_riser->right_riser_encoder->Reset();
	right_riser->right_riser_motor->Set(0);
}
