#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveWithJoystick: public CommandBase
{
public:
	DriveWithJoystick();
	void Initialize();
	void Execute();
	void Thresh(double, double);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
