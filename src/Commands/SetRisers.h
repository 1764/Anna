#ifndef SetRisers_H
#define SetRisers_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetRisers: public CommandBase
{
private:
	int target_;
public:
	SetRisers(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
