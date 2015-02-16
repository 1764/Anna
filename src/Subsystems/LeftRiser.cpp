#include "LeftRiser.h"
#include "../RobotMap.h"
#include "../Commands/SetLeftRiser.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/LeftRiserLimit.h"

LeftRiser::LeftRiser() :
		PIDSubsystem("LeftRiser", 0.0025, 0.0, 0.0)
{
	SetAbsoluteTolerance(12.55);
	left_riser_motor = new Talon(LEFT_RISER_MOTOR_PORT);
	left_riser_encoder = new Encoder(LEFT_RISER_ENCODER_A_PORT, LEFT_RISER_ENCODER_B_PORT);
	SetSetpoint(0);
	Enable();
}

double LeftRiser::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;	
	//std::cout << "Left Riser: " << left_riser_encoder->GetDistance() << "\n";
	return left_riser_encoder->GetDistance();
}

void LeftRiser::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	left_riser_motor->PIDWrite(output);
}

void LeftRiser::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new LeftRiserLimit());
}
