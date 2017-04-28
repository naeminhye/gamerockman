#include "OctopusBattery.h"

void OctopusBattery::updateLocation()
{
	if(octopusActivity == OCTOPUS_RUNNING)
		y += dy;
}

void OctopusBattery::update()
{
//	dx = -1;
	/*switch (Ocactivity)
	{
	case OCTOPUS_PREPARE:
		if (octopusDelay.isTerminated())
		{
			Ocactivity = OCTOPUS_RUN;
			octopusDelay.start(2000);
		}
		break;
	case OCTOPUS_RUN:
		direction = Right;
			dx = direction;
	
		break;
	default:
		break;
	}*/
	switch (octopusActivity)
	{
	case OCTOPUS_WAITING:
		if (octopusDelay.isTerminated())
		{
			octopusActivity = OCTOPUS_RUNNING;
			//	octopusDelay.start(2000);
		}
		break;
	case OCTOPUS_RUNNING:

		break;
		/*case OCTOPUS_CLOSE:
		if (octopusDelay.isTerminated())
		{
		Ocactivity = OCTOPUS_OPEN;
		setAction(OCTOPUS_OPEN_EYES);
		octopusDelay.start(TIME_OCTOPUS_OPEN_EYES);
		}
		break;
		case OCTOPUS_OPEN:
		if (octopusDelay.isTerminated())
		{
		Ocactivity = OCTOPUS_CLOSE;
		setAction(OCTOPUS_CLOSE_EYES);
		octopusDelay.start(TIME_OCTOPUS_CLOSE_EYES);
		}
		break;	*/
	default:
		break;
	}

	octopusDelay.update();


}

void OctopusBattery::onCollision(FBox * other, int nx, int ny)
{
	if (other->collisionType == CT_GROUND && ny != 0)
	{
	//	if (octopusDelay.isTerminated())
		{
			octopusDelay.start(2000);
		}
		octopusActivity = OCTOPUS_WAITING;
		dy = ny;
	}
}

OctopusBattery::OctopusBattery()
{
	//Ocactivity = OCTOPUS_CLOSE;
	octopusActivity = OCTOPUS_WAITING;
	octopusDelay.start(1000);
	dy = 1;
	dx = 0;
}


OctopusBattery::~OctopusBattery()
{
}
