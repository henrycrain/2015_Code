#include "SonarFeedback.h"

SonarFeedback::SonarFeedback(): Subsystem("SonarFeedback")
{
	greenBarRelay = new Relay(GREEN_BAR_RELAY_PORT, kForward);
}

void SonarFeedback::InitDefaultCommand()
{
	SetDefaultCommand(new RelayOutput);
}

void RelayOn()
{
	greenBarRelay->Set(kOn);
}

void RelayOff()
{
	greenBarRelay->Set(kOff);
}
