#ifndef ResetRightRiser_H
#define ResetRightRiser_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetRightRiser: public CommandBase
{
public:
	ResetRightRiser();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
