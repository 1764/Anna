#ifndef LeftRiserUp_H
#define LeftRiserUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class LeftRiserUp: public CommandBase
{
public:
	LeftRiserUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
