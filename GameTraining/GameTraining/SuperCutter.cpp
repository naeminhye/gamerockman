#include "SuperCutter.h"
#include "Rockman.h"

void SuperCutter::update()
{
	cutterDelay.update();
	float xCenterRockman, xCenter;
	xCenterRockman = Rockman::getInstance()->xCenter();
	xCenter = this->xCenter();
	
	switch (cutterActivity)
	{
	case SUPERCUTTER_WAITING:

		if (xCenterRockman > xCenter - SUPER_CUTTER_SHOOT_DISTANCE && xCenterRockman < xCenter + SUPER_CUTTER_SHOOT_DISTANCE)
		{
			cutterDelay.start();
			cutterActivity = SUPERCUTTER_SHOOTING;
		}
		break;
	case SUPERCUTTER_SHOOTING:

		if (!(xCenterRockman > xCenter - SUPER_CUTTER_SHOOT_DISTANCE && xCenterRockman < xCenter + SUPER_CUTTER_SHOOT_DISTANCE))
		{
			cutterActivity = SUPERCUTTER_WAITING;
			return;
		}
		if (cutterDelay.isTerminated())
		{
			xTarget = Rockman::getInstance()->xCenter();
			yTarget = Rockman::getInstance()->yCenter();

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
			bullet->vy = 0.4; // TODO:  luu constant
			float a = bullet->ay;
			float b = bullet->vy; // Vy0
			float c = bullet->y - yTarget;

			float t = (-b - sqrt((b * b - 4 * a * c))) / (2 * a);
			bullet->vx = (xTarget - bullet->x) / t;

			cutterDelay.start();
		}
		break;
	default:
		break;
	}
}

void SuperCutter::updateAttack()
{
	float xCenterRockman, xCenter;
	xCenterRockman = Rockman::getInstance()->xCenter();
	xCenter = this->xCenter();
	
	
}

SuperCutter::SuperCutter()
{
	collisionType = CT_NONE;
	cutterDelay.init(500);
	cutterActivity = SUPERCUTTER_WAITING;
}


SuperCutter::~SuperCutter()
{
}
