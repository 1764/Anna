#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
//ExampleSubsystem* CommandBase::examplesubsystem = NULL;
DriveTrain* CommandBase::drive_train = NULL;
LeftRiser* CommandBase::left_riser = NULL;
RightRiser* CommandBase::right_riser = NULL;
OI* CommandBase::oi = NULL;

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
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	//examplesubsystem = new ExampleSubsystem();
	//drive_train = new DriveTrain();
	left_riser = new LeftRiser();
	//right_riser = new RightRiser();
	oi = new OI();
}
