#ifndef MoveRisersUp_H
#define MoveRisersUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveRisersUp: public CommandBase
{
public:
	MoveRisersUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
