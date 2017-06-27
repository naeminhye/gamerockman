#include "OctopusBattery.h"

void OctopusBattery::updateLocation()
{
	if (octopusActivity == OCTOPUS_RUNNING)
	{
		switch (id)
		{
		case OCTOPUS_HORIZONTAL:
			y += dy;
			break;
		case OCTOPUS_VERTICAL:
			x += dx;
			break;
		default:
			break;
		}
	}
		
}

void OctopusBattery::update()
{
	switch (octopusActivity)
	{
	case OCTOPUS_WAITING:
		if (octopusDelay.isTerminated())
		{
			octopusActivity = OCTOPUS_RUNNING;
		}
		break;
	case OCTOPUS_RUNNING:
		setAction(OCTOPUS_OPEN_EYES);
		break;
	default:
		break;
	}

	octopusDelay.update();


}

void OctopusBattery::onCollision(FBox * other, int nx, int ny)
{
	switch (id)
	{
	case OCTOPUS_HORIZONTAL:
		if (other->collisionType == CT_GROUND && ny != 0)
		{
			{
				setAction(OCTOPUS_CLOSE_EYES);
				octopusDelay.start(OCTOPUS_WAITING_DELAYTIME);
				if (ny > 0)
				{
					y = other->top() + height;
				}
				else
				{
					y = other->bottom();
				}
			}
			octopusActivity = OCTOPUS_WAITING;
			dy = ny * OCTOPUS_VELOCITY;
			
		}
		break;
	case OCTOPUS_VERTICAL:
		if (other->collisionType == CT_GROUND && nx != 0)
		{
			{
				setAction(OCTOPUS_CLOSE_EYES);
				octopusDelay.start(OCTOPUS_WAITING_DELAYTIME);
				if (nx > 0)
				{
					x = other->right();
				}
				else
				{
					x = other->left() - width;
				}
			}
			octopusActivity = OCTOPUS_WAITING;
			dx = nx * OCTOPUS_VELOCITY;
		}
		break;
	default:
		break;
	}
	
}

void OctopusBattery::init()
{
	switch (id)
	{
	case OCTOPUS_HORIZONTAL:
		dy = OCTOPUS_VELOCITY;
		dx = 0;
		break;
	case OCTOPUS_VERTICAL:
		dy = 0;
		dx = OCTOPUS_VELOCITY;
		break;
	default:
		break;
	}
}

OctopusBattery::OctopusBattery()
{
	octopusActivity = OCTOPUS_WAITING;
	healthPoint = OCTOPUS_HEALTH_POINTS;
	attackDamage = OCTOPUS_ATTACK_DAMAGE;
	points = OCTOPUS_POINTS;
}


OctopusBattery::~OctopusBattery()
{
}
