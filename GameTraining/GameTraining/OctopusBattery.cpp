#include "OctopusBattery.h"





void OctopusBattery::updateOcsprite()
{
	switch (Ocactivity)
	{
	case OCTOPUS_WAITING:
		if (octopusDelay.isTerminated())
		{
			Ocactivity = OCTOPUS_RUN;
		//	octopusDelay.start(2000);
		}
		break;
	case OCTOPUS_RUN:
		
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

void OctopusBattery::updateLocation()
{
	if(Ocactivity == OCTOPUS_RUN)
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
	updateOcsprite();
}

void OctopusBattery::onCollision(FBox * other, int nx, int ny)
{
	if (other->collisionType == CT_GROUND && ny != 0)
	{
	//	if (octopusDelay.isTerminated())
		{
			octopusDelay.start(2000);
		}
		Ocactivity = OCTOPUS_WAITING;
		dy = ny;
	}
}

OctopusBattery::OctopusBattery()
{
	//Ocactivity = OCTOPUS_CLOSE;
	Ocactivity = OCTOPUS_WAITING;
	octopusDelay.start(1000);
	dy = 1;
	dx = 0;
}


OctopusBattery::~OctopusBattery()
{
}
