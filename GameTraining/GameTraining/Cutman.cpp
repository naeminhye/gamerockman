#include "Cutman.h"



void Cutman::update()
{
	Enemy::update();
	cutmanDelay.update();

	switch (cutmanActivity)
	{
	case CMA_WAITING:
		setAction(CM_WAITING);
		dx = 0;
		if (cutmanDelay.isTerminated())
		{
			cutmanActivity = CMA_RUNNING;
			cutmanDelay.start(1000); // TODO: luu constant 
		}
		break;
	case CMA_RUNNING:
		setAction(CM_RUNNING);
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

void Cutman::setAction(int actionValue)
{
	if (actionValue == CM_SHOOTING)
	{
		Enemy::setAction(actionValue);
		return;
	}
	if (cutmanAction != actionValue)
	{
		cutmanAction = (CUTMAN_ACTION)actionValue;
		this->action = cutmanType* CM_ACTION_COUNT + actionValue;
		frameIndex = 0;

	}
}

Cutman::Cutman()
{
	cutmanType = CM_NON_ATTACKING,
	cutmanActivity = CMA_WAITING;
	cutmanDelay.start(1000);
	direction = Left;
	dx = 0;
	healthPoint = 28;
}


Cutman::~Cutman()
{
}
