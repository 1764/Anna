#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/LeftRiser.h"
#include "Subsystems/RightRiser.h"
#include "Subsystems/DriveTrain.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();

	static OI *oi;
	static DriveTrain *drive_train;
	static LeftRiser *left_riser;
	static RightRiser *right_riser;
};

#endif
