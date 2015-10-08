#ifndef DisablePID_H
#define DisablePID_H

#include "../CommandBase.h"
#include "WPILib.h"

class DisablePID: public CommandBase
{
public:
	DisablePID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
