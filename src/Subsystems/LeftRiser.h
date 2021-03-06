#ifndef LeftRiser_H
#define LeftRiser_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class LeftRiser: public PIDSubsystem
{
private:
	//Victor *motor_;
	Talon *motor_;
	DigitalInput *reset_;

public:
	Encoder *encoder_;
public:
	LeftRiser();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	bool getReset();
};

#endif
