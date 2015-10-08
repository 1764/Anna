#ifndef RightRiser_H
#define RightRiser_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class RightRiser: public PIDSubsystem
{
private:
	Victor *motor_;
	DigitalInput *reset_;
	Encoder *encoder_;
public:
	RightRiser();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	bool getReset();
};

#endif
