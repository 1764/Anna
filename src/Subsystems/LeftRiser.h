#ifndef LeftRiser_H
#define LeftRiser_H

#include "Commands/PIDSubsystem.h"
#include "../RobotMap.h"
#include "WPILib.h"

class LeftRiser: public PIDSubsystem
{
public:
	SpeedController * left_riser_motor;
	Encoder * left_riser_encoder;
	LeftRiser();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
