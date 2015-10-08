#include "EnablePID.h"

EnablePID::EnablePID()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void EnablePID::Initialize()
{
	left_riser->Enable();
	right_riser->Enable();
}

// Called repeatedly when this Command is scheduled to run
void EnablePID::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EnablePID::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EnablePID::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnablePID::Interrupted()
{

}
