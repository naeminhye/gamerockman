#include "MGMGameTimeLoop.h"


MGMGameTimeLoop::MGMGameTimeLoop(DWORD tickPerFrame, int loopCount):
	MGMGameTime(tickPerFrame)
{
	setLoopCount(loopCount);
}

void MGMGameTimeLoop::setLoopCount(int loopCount)
{
	this->loopCount = loopCount;
}


bool MGMGameTimeLoop::atTime()
{
	if(!isTerminated())
	{
		if(MGMGameTime::atTime())
		{
			curLoop++;
			return true;
		}

		return false;
	}
	return false;
}
void MGMGameTimeLoop::start()
{
	curLoop=0;
	MGMGameTime::start();
}

bool MGMGameTimeLoop::isTerminated()
{
	return curLoop==loopCount;
}


MGMGameTimeLoop::~MGMGameTimeLoop(void)
{
}
