#include "MoveRisersDown.h"
#include "../RobotMap.h"

MoveRisersDown::MoveRisersDown()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(left_riser);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void MoveRisersDown::Initialize()
{
	left_riser->Enable();
	right_riser->Enable();
}

// Called repeatedly when this Command is scheduled to run
void MoveRisersDown::Execute()
{
	int setpoint = left_riser->GetSetpoint();

	if(setpoint > RISER_SPEED)
	{
		left_riser->SetSetpoint(setpoint - RISER_SPEED);
		right_riser->SetSetpoint(setpoint - RISER_SPEED);
	}
	else
	{
		left_riser->SetSetpoint(0);
		right_riser->SetSetpoint(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveRisersDown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveRisersDown::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveRisersDown::Interrupted()
{

}
