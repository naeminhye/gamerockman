#pragma once
#include "MGMgametime.h"
class MGMGameTimeLoop :
	public MGMGameTime
{
	int curLoop;
	int loopCount;
public:
	MGMGameTimeLoop(DWORD tickPerFrame, int loopCount);
	~MGMGameTimeLoop(void);

	void setLoopCount(int loopCount);

	bool isTerminated();
	bool atTime();
	void start();
};

