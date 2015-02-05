#include "MecanumTankDrive.h"

MecanumTankDrive::MecanumTankDrive()
{
	Requires(drivetrain);  // obviously drive modes need exclusive drivetrain access
}

void MecanumTankDrive::Initialize()
{
	return;
}

void MecanumTankDrive::Execute()
{
	drivetrain->front_right_motor->Set(oi->joystick2->GetY() + oi->joystick2->GetX());
	drivetrain->rear_right_motor->Set(oi->joystick2->GetY() - oi->joystick2->GetX());
	drivetrain->front_left_motor->Set(oi->joystick1->GetY() - oi->joystick1->GetX());
	drivetrain->rear_left_motor->Set(oi->joystick1->GetY() + oi->joystick1->GetX());
}

bool MecanumTankDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MecanumTankDrive::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumTankDrive::Interrupted()
{
	drivetrain->Stop();
}
