#include "ResetLifters.h"

ResetLifters::ResetLifters()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void ResetLifters::Initialize()
{
	std::cout << "Resting Lifters\n";
}

// Called repeatedly when this Command is scheduled to run
void ResetLifters::Execute()
{
	right_riser->MoveDown();
	left_riser->MoveDown();
}

// Make this return true when this Command no longer needs to run execute()
bool ResetLifters::IsFinished()
{
	return right_riser->MoveDown() && left_riser->MoveDown();
}

// Called once after isFinished returns true
void ResetLifters::End()
{
	std::cout << "Finished\n";
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetLifters::Interrupted()
{

}
