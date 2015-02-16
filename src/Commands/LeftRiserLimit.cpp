#include "LeftRiserLimit.h"

LeftRiserLimit::LeftRiserLimit()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
}

// Called just before this Command runs the first time
void LeftRiserLimit::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LeftRiserLimit::Execute()
{
	std::cout << oi->getLeftRiserLimit() << "\n";
}

// Make this return true when this Command no longer needs to run execute()
bool LeftRiserLimit::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LeftRiserLimit::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LeftRiserLimit::Interrupted()
{

}
