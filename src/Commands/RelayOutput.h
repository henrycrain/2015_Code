#ifndef RelayOutput_H
#define RelayOutput_H

#include "../CommandBase.h"
#include "WPILib.h"

class RelayOutput: public CommandBase
{
public:
	RelayOutput();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
