#ifndef ResetLeftRiser_H
#define ResetLeftRiser_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetLeftRiser: public CommandBase
{
public:
	ResetLeftRiser();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
