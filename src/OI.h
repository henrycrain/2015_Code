#ifndef OI_H
#define OI_H

#include "WPILib.h"

// currently set up for 2 joystick tank, add more features later!


class OI {
public:
	OI();
	Joystick *joystick0;
	Joystick *joystick1;
	Joystick *joystick2;
	Joystick *joystick3;
	Joystick *joystick4;
	Joystick *joystick5;
};

#endif
