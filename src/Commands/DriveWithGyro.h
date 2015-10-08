#ifndef DriveWithGyro_H
#define DriveWithGyro_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveWithGyro: public CommandBase
{
public:
	DriveWithGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double Thresh(double, double);
};

#endif
