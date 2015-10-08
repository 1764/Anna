#ifndef LeftRiserDown_H
#define LeftRiserDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class LeftRiserDown: public CommandBase
{
public:
	LeftRiserDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
