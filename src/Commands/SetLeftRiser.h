#ifndef SetLeftRiser_H
#define SetLeftRiser_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetLeftRiser: public CommandBase
{
private:
	bool was_pressed;
	int desired_position;
public:
	SetLeftRiser();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
