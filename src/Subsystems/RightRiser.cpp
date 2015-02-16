#include "RightRiser.h"
#include "../RobotMap.h"
#include "../OI.h"
#include "../Commands/SetRightRiser.h"

RightRiser::RightRiser() :
		Subsystem("ExampleSubsystem")
{
	right_riser_motor = new Victor(RIGHT_RISER_MOTOR_PORT);
	right_tracking_limit = new DigitalInput(RIGHT_TRACKING_LIMIT_PORT);
	right_reset_limit = new DigitalInput(RIGHT_RESET_LIMIT_PORT);
	top = 0;
	bottom = 0;
	was_pressed = false;
	last_direction = 0;
}

void RightRiser::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new SetRightRiser());
}

void RightRiser::Update()
{
	if(right_tracking_limit->Get())
	{
		if(!was_pressed)
		{
			//RisingEdge
			if(last_direction == 1)
			{
				bottom += 1;
			}
			else if(last_direction == -1)
			{
				top -= 1;
			}
		}

		was_pressed = true;
	}
	else
	{
		if(was_pressed)
		{
			//FallingEdge
			if(last_direction == 1)
			{
				top += 1;
			}
			else if(last_direction == -1)
			{
				bottom -= 1;
			}
		}

		was_pressed = false;
	}
}

void RightRiser::MoveUp()
{
	last_direction = 1;
	right_riser_motor->Set(-0.42);
}

bool RightRiser::MoveDown()
{
	if(right_reset_limit->Get())
	{
		last_direction = 0;
		Stop();
		top = 0;
		bottom = 0;
		return true;
	}
	else
	{
		last_direction = -1;
		right_riser_motor->Set(0.28);
		return false;
	}
}

void RightRiser::Stop()
{
	right_riser_motor->Set(0.0);
}

int RightRiser::GetTop()
{
	return top;
}

int RightRiser::GetBottom()
{
	return bottom;
}
