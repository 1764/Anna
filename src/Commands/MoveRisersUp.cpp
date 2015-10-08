#include "MoveRisersUp.h"
#include "../RobotMap.h"

MoveRisersUp::MoveRisersUp()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
	Requires(right_riser);
}

// Called just before this Command runs the first time
void MoveRisersUp::Initialize()
{
	left_riser->Enable();
	right_riser->Enable();
}

// Called repeatedly when this Command is scheduled to run
void MoveRisersUp::Execute()
{
	int setpoint = left_riser->GetSetpoint();

	if(setpoint < MAX_HEIGHT)
	{
		left_riser->SetSetpoint(setpoint + RISER_SPEED);
		right_riser->SetSetpoint(setpoint + RISER_SPEED);
	}
	else
	{
		left_riser->SetSetpoint(MAX_HEIGHT + RISER_SPEED);
		right_riser->SetSetpoint(MAX_HEIGHT + RISER_SPEED);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveRisersUp::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveRisersUp::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveRisersUp::Interrupted()
{

}
