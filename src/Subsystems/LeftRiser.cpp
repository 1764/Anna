#include "LeftRiser.h"
#include "../RobotMap.h"
#include "../OI.h"
#include "../Commands/SetLeftRiser.h"

LeftRiser::LeftRiser() :
		Subsystem("ExampleSubsystem")
{
	left_riser_motor = new Victor(LEFT_RISER_MOTOR_PORT);
	left_tracking_limit = new DigitalInput(LEFT_TRACKING_LIMIT_PORT);
	left_reset_limit = new DigitalInput(LEFT_RESET_LIMIT_PORT);
	top = 0;
	bottom = 0;
	was_pressed = false;
	last_direction = 0;
}

void LeftRiser::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new SetLeftRiser());
}

void LeftRiser::Update()
{
	if(left_tracking_limit->Get())
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

void LeftRiser::MoveUp()
{
	last_direction = 1;
	left_riser_motor->Set(-0.5);
}

bool LeftRiser::MoveDown()
{
	if(left_reset_limit->Get())
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
		left_riser_motor->Set(0.4);
		return false;
	}
}

void LeftRiser::Stop()
{
	left_riser_motor->Set(0.0);
}

int LeftRiser::GetTop()
{
	return top;
}

int LeftRiser::GetBottom()
{
	return bottom;
}
