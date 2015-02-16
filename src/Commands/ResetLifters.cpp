#include "ResetLifters.h"
#include "ResetLeftRiser.h"
#include "ResetRightRiser.h"

ResetLifters::ResetLifters()
{
	AddParallel(new ResetLeftRiser());
	AddSequential(new ResetRightRiser());
}
