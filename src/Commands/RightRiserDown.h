#ifndef RightRiserDown_H
#define RightRiserDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class RightRiserDown: public CommandBase
{
public:
	RightRiserDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
