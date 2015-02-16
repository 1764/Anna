#ifndef RightRiser_H
#define RightRiser_H

#include "Commands/PIDSubsystem.h"
#include "../RobotMap.h"
#include "WPILib.h"

class RightRiser: public PIDSubsystem
{
public:
	SpeedController * right_riser_motor;
	Encoder * right_riser_encoder;
	RightRiser();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
