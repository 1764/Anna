#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor *back_left_drive_motor, *back_right_drive_motor, *front_left_drive_motor, *front_right_drive_motor;
public:
	DriveTrain();
	void SetMotor(double, double, double);
	void InitDefaultCommand();
};

#endif
