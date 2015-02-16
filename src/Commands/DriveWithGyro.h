#ifndef DriveWithGyro_H
#define DriveWithGyro_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveWithGyro: public CommandBase
{
	double angle;
public:
	DriveWithGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
