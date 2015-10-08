#include <Subsystems/Riser.h>
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

Riser::Riser(int motorPort, int resetPort, int encoderAPort, int encoderBPort) :
		PIDSubsystem("LeftRiser", 0.015, 0.0001, 0.0001)
{
	motor_ = new Victor(motorPort);
	reset_ = new DigitalInput(resetPort);
	encoder_ = new Encoder(encoderAPort, encoderBPort);
}

double Riser::ReturnPIDInput()
{
	return encoder_->Get();
}

void Riser::UsePIDOutput(double output)
{
	if(reset_->Get())
	{
		encoder_->Reset();
		if(this->GetSetpoint() < this->GetPosition())
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

void Riser::InitDefaultCommand()
{
}

bool Riser::getReset()
{
	return reset_->Get();
}
