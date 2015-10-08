#ifndef Riser_H
#define Riser_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class Riser: public PIDSubsystem
{
private:
	Victor *motor_;
	DigitalInput *reset_;
	Encoder *encoder_;
public:
	Riser(int, int, int, int);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	bool getReset();
};

#endif
