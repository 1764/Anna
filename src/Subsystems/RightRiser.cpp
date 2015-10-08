#include "RightRiser.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

RightRiser::RightRiser() :
		PIDSubsystem("RightRightRiser", 0.015, 0.0001, 0.0001)
{
	motor_ = new Victor(RIGHT_RISER_MOTOR_PORT);
	reset_ = new DigitalInput(RIGHT_RESET_LIMIT_PORT);
	encoder_ = new Encoder(RIGHT_ENCODER_A_PORT, RIGHT_ENCODER_B_PORT);
}

double RightRiser::ReturnPIDInput()
{
	return encoder_->Get();
}

void RightRiser::UsePIDOutput(double output)
{
	std::cout << "RIGHT:" << encoder_->Get() << "\n";
	if(reset_->Get())
	{
		encoder_->Reset();
		if(output < 0)
		{
			this->SetSetpoint(0);
			motor_->Set(0);
		}
		else
		{
			motor_->Set(output);
		}
	}
	else
	{
		motor_->Set(output);
	}
}

void RightRiser::InitDefaultCommand()
{
}

bool RightRiser::getReset()
{
	return reset_->Get();
}
