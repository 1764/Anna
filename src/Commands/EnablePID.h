#ifndef EnablePID_H
#define EnablePID_H

#include "../CommandBase.h"
#include "WPILib.h"

class EnablePID: public CommandBase
{
public:
	EnablePID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
