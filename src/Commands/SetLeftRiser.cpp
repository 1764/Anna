#include "SetLeftRiser.h"
#include <iostream>

SetLeftRiser::SetLeftRiser()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
}

// Called just before this Command runs the first time
void SetLeftRiser::Initialize()
{
	//left_riser->Disable();
}

// Called repeatedly when this Command is scheduled to run
void SetLeftRiser::Execute()
{
	left_riser->SetSetpoint((oi->getCopilotStickThrottle()-1) * 747);
	//std::cout << left_riser->GetPosition() << "\n";
	//left_riser->left_riser_motor->Set(oi->getCopilotStickThrottle());
}

// Make this return true when this Command no longer needs to run execute()
bool SetLeftRiser::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SetLeftRiser::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLeftRiser::Interrupted()
{

}
