#include "OctopusBattery.h"



void OctopusBattery::update()
{
	//if (rm_action == OCTOPUS_WAITING)
	//	return;
	//blinkDelay.update();
	//switch (blinkActivity)
	//{
	//case WAITING_OPEN:
	//	setAction(OCTOPUS_WAITING);
	//	if (blinkDelay.isTerminated())
	//	{
	//		blinkActivity = WAITING_CLOSE;
	//		blinkDelay.start(TIME_OCTOPUS_CLOSE);
	//	}
	//	return;
	//case WATING_CLOSE:
	//	setAction(OCTOPUS_RUNNING);
	//	if (blinkDelay.isTerminated())
	//	{
	//		blinkActivity = WAITING_OPEN;
	//		blinkDelay.start(TIME_WATING_OPEN);
	//	}
	//	return;
	//default:
	//	break;
	//}
}

OctopusBattery::OctopusBattery()
{
	int a = 5;
}


OctopusBattery::~OctopusBattery()
{
}
