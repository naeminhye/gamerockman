#include "Cutman.h"



void Cutman::update()
{
	Enemy::update();
	cutmanDelay.update();

	switch (cutmanActivity)
	{
	case CMA_WAITING:
		setAction(CM_WAITING_WITH_KNIFE);
		dx = 0;
		if (cutmanDelay.isTerminated())
		{
			cutmanActivity = CMA_RUNNING;
			cutmanDelay.start(1000); // TODO: luu constant 
		}
		break;
	case CMA_RUNNING:
		setAction(CM_RUNNING_WITH_KNIFE);
		dx = -1;
		if (cutmanDelay.isTerminated())
		{
			if (abs(getXCenter() - Rockman::getInstance()->getXCenter()) < 50) // TODO: luu constant 
				cutmanActivity = CMA_SHOOTING;
			else
			{
				cutmanActivity = CMA_WAITING;
				cutmanDelay.start(1000); 
			}
		}
		break;
	case CMA_SHOOTING:
		setAction(CM_SHOOTING);
		dx = 0;
		break;
	case CMA_JUMPING:
		if (cutmanDelay.isTerminated())
		{
			cutmanActivity = CMA_WAITING;
			cutmanDelay.start(1000);
		}
		break;
	default:
		break;
	}
}

void Cutman::onLastFrameAnimation()
{
	if (cutmanActivity == CMA_SHOOTING)
	{
		setAction(CM_JUMPING); 
		cutmanActivity = CMA_JUMPING;
		cutmanDelay.start(1000); 
		vy = CUTMAN_JUMP_VY; 
		
	}
}

Cutman::Cutman()
{
	cutmanActivity = CMA_WAITING;
	cutmanDelay.start(1000);
	direction = Left;
	dx = 0;
	healthPoint = 28;
}


Cutman::~Cutman()
{
}
