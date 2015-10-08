#include <Commands/AutonomousCommandGroup.h>
#include <Commands/TrashAuto.h>
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	Command *autonomousCommand;

	void RobotInit()
	{
		CommandBase::init();
		//SmartDashboard::PutNumber("Gyro", gyro->GetAngle());
		SmartDashboard::PutBoolean("tote", false);
		lw = LiveWindow::GetInstance();
		CameraServer::GetInstance()->SetQuality(50);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if(SmartDashboard::GetBoolean("tote"))
		{
			autonomousCommand = new AutonomousCommandGroup();
		}
		else
		{
			autonomousCommand = new TrashAuto();
		}

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

