#ifndef LeftRiser_H
#define LeftRiser_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LeftRiser: public Subsystem
{
private:
	SpeedController *left_riser_motor;
	DigitalInput *left_tracking_limit;
	DigitalInput *left_reset_limit;
	int top, bottom;
	bool was_pressed;
	int last_direction;
public:
	LeftRiser();
	void InitDefaultCommand();
	void Update();
	void MoveUp();
	bool MoveDown();
	void Stop();
	int GetTop();
	int GetBottom();
};

#endif
