#include "SuperCutter.h"
#include "Rockman.h"

void SuperCutter::update()
{
	cutterDelay.update();
	int xCenterRockman, xCenter;
	xCenterRockman = Rockman::getInstance()->xCenter();
	xCenter = this->xCenter();
	
	switch (cutterActivity)
	{
	case SUPERCUTTER_WAITING:

		if (xCenterRockman > xCenter - 50 && xCenterRockman < xCenter + 50)
		{
			cutterDelay.start();
			cutterActivity = SUPERCUTTER_SHOOTING;
		}
		break;
	case SUPERCUTTER_SHOOTING:

		if (!(xCenterRockman > xCenter - 50 && xCenterRockman < xCenter + 50))
		{
			cutterActivity = SUPERCUTTER_WAITING;
			return;
		}
		if (cutterDelay.isTerminated())
		{
			SuperCutterBullet* bullet = new SuperCutterBullet();
			if (xCenter > xCenterRockman)
			{
				bullet->direction = Left;
			}
			else
				bullet->direction = Right;
			bullet->vy = 0.4;
			bullet->x = x;
			bullet->dx = 0;
			bullet->y = y;
			cutterDelay.start();
		}
		break;
	default:
		break;
	}
}

SuperCutter::SuperCutter()
{
	cutterDelay.init(500);
	cutterActivity = SUPERCUTTER_WAITING;
}


SuperCutter::~SuperCutter()
{
}
