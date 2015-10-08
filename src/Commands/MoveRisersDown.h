#ifndef MoveRisersDown_H
#define MoveRisersDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveRisersDown: public CommandBase
{
public:
	MoveRisersDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
