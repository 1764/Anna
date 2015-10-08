#include <Commands/AutonomousCommandGroup.h>
#include "Commands/ResetRisers.h"
#include "Commands/DriveWithGyroTime.h"
#include "Commands/ResetGyro.h"
#include "Commands/SetRisers.h"
#include "Commands/WaitF.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential(new ResetGyro());
	AddSequential(new DriveWithGyroTime(0, -0.5, 0, 0.3));
	AddSequential(new ResetRisers());
	AddSequential(new SetRisers(100));
	AddSequential(new DriveWithGyroTime(0, 0.5, 0, 0.3));
	AddSequential(new DriveWithGyroTime(-0.75, 0, 0, 2.3));
	AddSequential(new SetRisers(0));
	AddSequential(new WaitF());
}
