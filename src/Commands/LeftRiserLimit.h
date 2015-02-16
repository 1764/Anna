#ifndef LeftRiserLimit_H
#define LeftRiserLimit_H

#include "../CommandBase.h"
#include "WPILib.h"

class LeftRiserLimit: public CommandBase
{
public:
	LeftRiserLimit();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
