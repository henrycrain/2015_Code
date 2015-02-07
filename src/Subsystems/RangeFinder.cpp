#include "RangeFinder.h"

RangeFinder::RangeFinder() :
	Subsystem("RangeFinder")
{
	rangefinder = new AnalogInput(RANGEFINDER_CHANNEL);
	relay = new Relay(RELAY_PORT_0, kForward);
}

void RangeFinder::InitDefaultCommand()
{
	SetDefaultCommand(new PrintRange());
}

float RangeFinder::GetVoltage()
{
	rangefinder->SetAverageBits(4);
	return rangefinder->GetAverageVoltage();
}

float RangeFinder::GetRangeIn()
{
	return GetVoltage() * IN_FACTOR;
}

float RangeFinder::GetRangeFt()
{
	return GetVoltage() * FT_FACTOR;
}

void LightOn()
{
	relay->Set(kOn);
}

void LightOff()
{
	relay->Set(kOff);
}
