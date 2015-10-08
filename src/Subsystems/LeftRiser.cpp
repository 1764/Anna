#include "LeftRiser.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

LeftRiser::LeftRiser() :
		PIDSubsystem("LeftRiser", 0.015, 0.0001, 0.0001)
{
	motor_ = new Victor(LEFT_RISER_MOTOR_PORT);
	reset_ = new DigitalInput(LEFT_RESET_LIMIT_PORT);
	encoder_ = new Encoder(LEFT_ENCODER_A_PORT, LEFT_ENCODER_B_PORT);
}

double LeftRiser::ReturnPIDInput()
{
	return encoder_->Get();
}

void LeftRiser::UsePIDOutput(double output)
{
	std::cout << "LEFT:" << encoder_->Get() << "\n";
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

void LeftRiser::InitDefaultCommand()
{
}

bool LeftRiser::getReset()
{
	return reset_->Get();
}
