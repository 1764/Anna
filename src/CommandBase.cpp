#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/Scheduler.h"
#include "RobotMap.h"

OI *CommandBase::oi = NULL;
DriveTrain *CommandBase::drive_train = NULL;
LeftRiser *CommandBase::left_riser = NULL;
RightRiser *CommandBase::right_riser = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	drive_train = new DriveTrain();
	left_riser = new LeftRiser();
	right_riser = new RightRiser();
	oi = new OI();
}
