#include "SetRightRiser.h"

SetRightRiser::SetRightRiser()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(right_riser);
	was_pressed = false;
	desired_position = 0;
}

// Called just before this Command runs the first time
void SetRightRiser::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetRightRiser::Execute()
{
	if(oi->getCopilotJoystickButton(8))
	{
		if(!was_pressed)
		{
			desired_position += 1;
			was_pressed = true;
		}
	}
	else if(oi->getCopilotJoystickButton(9))
	{
		if(!was_pressed)
		{
			desired_position -= 1;
			was_pressed = true;
		}
	}
	else
	{
		was_pressed = false;
	}
	/*
	if(oi->getCopilotJoystickButton(11))
	{
		right_riser->MoveUp();
	}
	else if(oi->getCopilotJoystickButton(10))
	{
		right_riser->MoveDown();
	}
	else
	{
		right_riser->Stop();
	}
	*/
	right_riser->Update();

	if(desired_position > right_riser->GetTop() && oi->getCopilotThrottle() > 0)
		right_riser->MoveUp();
	else if(desired_position < right_riser->GetTop() && oi->getCopilotThrottle() > 0)
		right_riser->MoveDown();
	else if(oi->getCopilotJoystickButton(11) && oi->getCopilotThrottle() < 0)
		right_riser->MoveUp();
	else if(oi->getCopilotJoystickButton(10) && oi->getCopilotThrottle() < 0)
		right_riser->MoveDown();
	else
		right_riser->Stop();

	if(oi->getReset())
	{
		if(right_riser->MoveDown())
			desired_position = 0;
	}

	/*
	std::cout << "RiserPosition:" << right_riser->GetPosition() << "\n";
	std::cout << "DesiredPosition:" << desired_position << "\n";
	*/
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
