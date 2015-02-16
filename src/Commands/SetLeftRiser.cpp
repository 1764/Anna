#include "SetLeftRiser.h"

SetLeftRiser::SetLeftRiser()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(left_riser);
	was_pressed = false;
	desired_position = 0;
}

// Called just before this Command runs the first time
void SetLeftRiser::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetLeftRiser::Execute()
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
	if(oi->getCopilotJoystickButton(6))
	{
		left_riser->MoveUp();
	}
	else if(oi->getCopilotJoystickButton(7))
	{
		left_riser->MoveDown();
	}
	else
	{
		left_riser->Stop();
	}
	*/

	left_riser->Update();

	if(desired_position > left_riser->GetTop() && oi->getCopilotThrottle() > 0)
		left_riser->MoveUp();
	else if(desired_position < left_riser->GetTop() && oi->getCopilotThrottle() > 0)
		left_riser->MoveDown();
	else if(oi->getCopilotJoystickButton(6) && oi->getCopilotThrottle() < 0)
		left_riser->MoveUp();
	else if(oi->getCopilotJoystickButton(7) && oi->getCopilotThrottle() < 0)
		left_riser->MoveDown();
	else
		left_riser->Stop();



	if(oi->getReset())
		{
			if(left_riser->MoveDown())
				desired_position = 0;
		}
	/*
	std::cout << "RiserPosition:" << left_riser->GetPosition() << "\n";
	std::cout << "DesiredPosition:" << desired_position << "\n";
	*/
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
