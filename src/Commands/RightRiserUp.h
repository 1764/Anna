#ifndef RightRiserUp_H
#define RightRiserUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class RightRiserUp: public CommandBase
{
public:
	RightRiserUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
