#include "RightRiser.h"
#include "../RobotMap.h"
#include "../Commands/SetRightRiser.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

RightRiser::RightRiser() :
		PIDSubsystem("RightRiser", 0.0025, 0.0, 0.0)
{
	SetAbsoluteTolerance(20);
	right_riser_motor = new Talon(RIGHT_RISER_MOTOR_PORT);
	right_riser_encoder = new Encoder(RIGHT_RISER_ENCODER_A_PORT, RIGHT_RISER_ENCODER_B_PORT);
	SetSetpoint(0);
	Enable();
}

double RightRiser::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;	
	//std::cout << "Right Encoder: " << right_riser_encoder->GetDistance() << "\n";
	return right_riser_encoder->GetDistance();
}

void RightRiser::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	right_riser_motor->PIDWrite(output);
}

void RightRiser::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new SetRightRiser());
}
