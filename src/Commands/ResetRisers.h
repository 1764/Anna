#ifndef ResetRisers_H
#define ResetRisers_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetRisers: public CommandBase
{
public:
	ResetRisers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
