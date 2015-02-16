#ifndef SetRightRiser_H
#define SetRightRiser_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetRightRiser: public CommandBase
{
private:
	bool was_pressed;
	int desired_position;
public:
	SetRightRiser();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
