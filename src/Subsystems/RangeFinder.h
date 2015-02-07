#ifndef RangeFinder_H
#define RangeFinder_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

#include "../RobotMap.h"
#include "../Commands/PrintRange.h"
#include "../OI.h"

#define IN_FACTOR 1 / .0098
#define FT_FACTOR IN_FACTOR / 12

class RangeFinder: public Subsystem
{
private:
	AnalogInput *sonar;
	Relay *relay;
public:
	RangeFinder(OI*);
	void InitDefaultCommand();
	float GetVoltage();
	float GetRangeIn();
	float GetRangeFt();
	void LightOn();
	void LightOff();
	OI *o = NULL;
};

#endif
