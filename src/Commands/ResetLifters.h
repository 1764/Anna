#ifndef ResetLifters_H
#define ResetLifters_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetLifters: public CommandBase
{
public:
	ResetLifters();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
