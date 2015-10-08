#ifndef DriveWithTime_H
#define DriveWithTime_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveWithTime: public CommandBase
{
private:
	double x, y, z, time;
public:
	DriveWithTime(double, double, double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
