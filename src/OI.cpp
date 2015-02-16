#include "OI.h"
#include "RobotMap.h"
#include "Commands/ResetLifters.h"

OI::OI()
{
	// Process operator interface input here.
	copilot_stick = new Joystick(COPILOT_STICK_PORT);
	pilot_stick = new Joystick(PILOT_STICK_PORT);
	left_limit = new DigitalInput(LEFT_LIMIT_PORT);
	right_limit = new DigitalInput(RIGHT_LIMIT_PORT);
	pilot_trigger = new JoystickButton(pilot_stick, 1);
	copilot_trigger = new JoystickButton(copilot_stick, 1);
	copilot_trigger->WhenPressed(new ResetLifters());
	left_ultrasonic = new AnalogInput(LEFT_ULTRASONIC_PORT);
	right_ultrasonic = new AnalogInput(RIGHT_ULTRASONIC_PORT);
	gyro = new Gyro(GYRO_PORT);
	left_riser_limit = new DigitalInput(LEFT_RISER_LIMIT_PORT);
	right_riser_limit = new DigitalInput(RIGHT_RISER_LIMIT_PORT);
}

double OI::getDriverJoystickX()
{
	return pilot_stick->GetX();
}

double OI::getDriverJoystickY()
{
	return pilot_stick->GetY();
}

double OI::getDriverJoystickZ()
{
	return pilot_stick->GetThrottle();
}

double OI::getCopilotStickThrottle()
{
	return copilot_stick->GetZ();
}

bool OI::getLeftLimit()
{
	std::cout << "Left Limit: " << left_limit->Get() << " ";
	return left_limit->Get();
}

bool OI::getRightLimit()
{
	std::cout << "Right Limit: " << right_limit->Get() << "\n";
	return right_limit->Get();
}

double OI::getLeftUltrasonic()
{
	return left_ultrasonic->GetAverageVoltage() * 96;
}

double OI::getRightUltrasonic()
{
	return right_ultrasonic->GetAverageVoltage() * 96;
}

double OI::getGyro()
{
	std::cout << "Gyro: " << gyro->GetAngle() << "\n";
	return gyro->GetAngle();
}

bool OI::getLeftRiserLimit()
{
	return left_riser_limit->Get();
}

bool OI::getRightRiserLimit()
{
	return right_riser_limit->Get();
}
