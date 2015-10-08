#ifndef WaitF_H
#define WaitF_H

#include "../CommandBase.h"
#include "WPILib.h"

class WaitF: public CommandBase
{
public:
	WaitF();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
