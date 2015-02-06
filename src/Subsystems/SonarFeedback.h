#ifndef Relays_H
#define Relays_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
#include "../Commands/RelayOutput.h"
#include "Relay.h"

class SonarFeedback: public Subsystem
{
private:
	Relay *greenBarRelay;
public:
	SonarFeedback();
	void InitDefaultCommand();
	void RelayOn();
	void RelayOff();
};

#endif
