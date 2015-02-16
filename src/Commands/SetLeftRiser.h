#ifndef SetLeftRiser_H
#define SetLeftRiser_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetLeftRiser: public CommandBase
{
public:
	SetLeftRiser();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
