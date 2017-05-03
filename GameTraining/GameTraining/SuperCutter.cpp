#include "SuperCutter.h"
#include "Rockman.h"

void SuperCutter::update()
{
	cutterDelay.update();
	float xCenterRockman, xCenter;
	xCenterRockman = Rockman::getInstance()->xCenter();
	xCenter = this->xCenter();
	double delta;
	
	switch (cutterActivity)
	{
	case SUPERCUTTER_WAITING:

		if (xCenterRockman > xCenter - CUTTER_SHOOT_DISTANCE && xCenterRockman < xCenter + CUTTER_SHOOT_DISTANCE)
		{
			cutterDelay.start();
			cutterActivity = SUPERCUTTER_SHOOTING;
		}
		break;
	case SUPERCUTTER_SHOOTING:

		if (!(xCenterRockman > xCenter - CUTTER_SHOOT_DISTANCE && xCenterRockman < xCenter + CUTTER_SHOOT_DISTANCE))
		{
			cutterActivity = SUPERCUTTER_WAITING;
			return;
		}
		if (cutterDelay.isTerminated())
		{
			xTarget = Rockman::getInstance()->x;
			yTarget = Rockman::getInstance()->y;

			SuperCutterBullet* bullet = new SuperCutterBullet();

			bullet->x = x;
			bullet->y = y;
			if (xCenter > xCenterRockman)
			{
				bullet->direction = Left;
			}
			else
			{
				bullet->direction = Right;
			}
			bullet->vy = CUTTER_BULLET_VY; 

			delta = bullet->vy*bullet->vy - 4 * bullet->ay*(y-yTarget);

			bullet->vx = (xTarget - x) *  ay / (-bullet->vy - sqrt(delta));

			cutterDelay.start();
		}
		break;
	default:
		break;
	}
}

SuperCutter::SuperCutter()
{
	collisionType = CT_NONE;
	cutterDelay.init(CUTTER_SHOOTING_DELAYTIME);
	cutterActivity = SUPERCUTTER_WAITING;
}


SuperCutter::~SuperCutter()
{
}
