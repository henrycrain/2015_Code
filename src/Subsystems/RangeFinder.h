#ifndef RangeFinder_H
#define RangeFinder_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

#include "../RobotMap.h"
#include "../Commands/PrintRange.h"

#define IN_FACTOR 1 / .0098
#define FT_FACTOR IN_FACTOR / 12

class RangeFinder: public Subsystem
{
private:
	AnalogInput *rangefinder;
	Relay *relay;
public:
	RangeFinder();
	void InitDefaultCommand();
	float GetVoltage();
	float GetRangeIn();
	float GetRangeFt();
	void LightOn();
	void LightOff();
};

#endif
