#ifndef LaunchPadOutput_H
#define LaunchPadOutput_H

#include "../CommandBase.h"
#include "WPILib.h"

class LaunchPadOutput: public CommandBase
{
public:
	LaunchPadOutput();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
