#ifndef DriveWithGyroTime_H
#define DriveWithGyroTime_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveWithGyroTime: public CommandBase
{
private:
	double x, y, z, time;
public:
	DriveWithGyroTime(double, double, double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
