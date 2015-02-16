#ifndef RightRiser_H
#define RightRiser_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class RightRiser: public Subsystem
{
private:
	SpeedController *right_riser_motor;
	DigitalInput *right_tracking_limit;
	DigitalInput *right_reset_limit;
	int top, bottom;
	bool was_pressed;
	int last_direction;
public:
	RightRiser();
	void InitDefaultCommand();
	void Update();
	void MoveUp();
	bool MoveDown();
	void Stop();
	int GetTop();
	int GetBottom();
};

#endif
