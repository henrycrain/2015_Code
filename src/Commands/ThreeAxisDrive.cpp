#include "ThreeAxisDrive.h"
#include "math.h"
ThreeAxisDrive::ThreeAxisDrive()
{
	Requires(drivetrain);
}

void ThreeAxisDrive::Initialize()
{

}

void ThreeAxisDrive::Execute()
{

	// The drivetrain->Go() method has built in handling for reversing motors on the left side...
	/* */

	float x = 0, y = 0, t = 0; // floats for the axes x, y, twist
	float fl = 0, fr = 0, rl = 0, rr = 0; // floats for the motor outputs

	if (abs(oi->joystick3->GetY() > .1)){
		y = oi->joystick3->GetY();
	}
	if (abs(oi->joystick3->GetX() > .1)){
		x = oi->joystick3->GetX();
	}
	if (abs(oi->joystick3->GetTwist() > .1)){
		t = oi->joystick3->GetTwist();
	}
	fl = y - t + x; // Front Left Wheel
	fr = y + t - x; // Front Right Wheel
	rl = y - t - x; // Rear Left Wheel
	rr = y + t + x; // Rear Right Wheel

	drivetrain->Go(fl,fr,rl,rr);
	/*
	// Alternatively, we can send the joystick inputs directly to the drivetrain->xxx->Set() methods
	drivetrain->front_left_motor->Set(oi->joystick_3->GetTwist() - oi->joystick_3->GetY() - oi->joystick_3->GetX());
	drivetrain->front_right_motor->Set(oi->joystick_3->GetTwist() + oi->joystick_3->GetY() + oi->joystick_3->GetX());
	drivetrain->rear_left_motor->Set(oi->joystick_3->GetTwist() - oi->joystick_3->GetY() + oi->joystick_3->GetX());
	drivetrain->rear_right_motor->Set(oi->joystick_3->GetTwist() + oi->joystick_3->GetY() - oi->joystick_3->GetX());
	*/
}

// Make this return true when this Command no longer needs to run execute()
bool ThreeAxisDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ThreeAxisDrive::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ThreeAxisDrive::Interrupted()
{
	drivetrain->Stop();
}
