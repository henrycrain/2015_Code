#include "RangeFinder.h"

RangeFinder::RangeFinder(OI *operatorInterface): Subsystem("RangeFinder")
{
	sonar = new AnalogInput(RANGEFINDER_CHANNEL);
	relay = new Relay(RELAY_PORT_0, Relay::kForward);
	o = operatorInterface;
}

void RangeFinder::InitDefaultCommand()
{
	SetDefaultCommand(new PrintRange());
}

float RangeFinder::GetVoltage()
{
	sonar->SetAverageBits(4);
	return sonar->GetAverageVoltage();
}

float RangeFinder::GetRangeIn()
{
	return GetVoltage() * IN_FACTOR;
}

float RangeFinder::GetRangeFt()
{
	return GetVoltage() * FT_FACTOR;
}

void RangeFinder::LightOn()
{
	relay->Set(Relay::kOn);
	o->joystick5->SetOutput(1, true);
}

void RangeFinder::LightOff()
{
	relay->Set(Relay::kOff);
	o->joystick5->SetOutput(1, false);
}
