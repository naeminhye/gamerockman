#include "Cutman.h"
#include "CutmanScissors.h"

extern int randomFrom(int numBegin, int numEnd);

void Cutman::updateWaiting()
{
	vx = 0;
	setAction(CM_WAITING);
	if (cutmanDelay.isTerminated())
	{
		selectActivity(CAR_WAITING);
		if (!checkNearRockman())
		{
			setActivity(CMA_RUNNING);
		}
		cutmanDelay.start(1000); // TODO: luu constant 
	}
}
void Cutman::updateRunning()
{
	setAction(CM_RUNNING);
	if (checkNearRockman())
	{
		setActivity(CMA_JUMPING);
		cutmanDelay.start(1000); // TODO: luu constant 
	}
}
void Cutman::updateJumping()
{
	if (ground && cutmanAction == CM_JUMPING)
	{
		selectActivity(CAR_JUMPING);
		cutmanDelay.start(1000); // TODO: luu constant 
	}
	setAction(CM_JUMPING);
	if (!checkNearRockman())
	{
		setActivity(CMA_RUNNING);
	}
}
void Cutman::updateShooting()
{
	vx = 0;
	setAction(CM_SHOOTING);
}

void Cutman::update()
{
	Flickable::updateFlicker();
	cutmanDelay.update();
	if(cutmanActivity != CMA_JUMPING)
		Enemy::initDirectionFollowRockman();
	vx = direction * 0.1; // TODO luu constant
	switch (cutmanActivity)
	{
	case CMA_WAITING:
		updateWaiting();
		break;
	case CMA_RUNNING:
		updateRunning();
		break;
	case CMA_SHOOTING:
		updateShooting();
		break;
	case CMA_JUMPING:
		updateJumping();
		break;
	default:
		break;
	}
	Enemy::update();
}

void Cutman::onLastFrameAnimation()
{
	if (cutmanActivity == CMA_SHOOTING)
	{
		if (!checkNearRockman())
		{
			selectActivity(CAR_SHOOTING);
		}
		setActivity(CMA_WAITING);
		cutmanDelay.start(1000); // TODO: luu constant
	}
}

bool Cutman::checkNearRockman()
{
	float delta = 50; // TODO: luu constant
	return abs(getXCenter() - Rockman::getInstance()->getXCenter()) < delta;
}

void Cutman::selectActivity(CUTMAN_ACTIVITY_RAND except)
{
	CUTMAN_ACTIVITY_RAND random;
	while ((random = (CUTMAN_ACTIVITY_RAND)randomFrom(CAR_WAITING, CAR_SHOOTING)) == except);

	switch (random)
	{
	case CAR_WAITING:
		setActivity(CMA_WAITING);
		break;
	case CAR_JUMPING:
		if (ground)
		{
			setActivity(CMA_JUMPING);
		}
		else
		{
			if (except == CAR_WAITING)
			{
				setActivity(CMA_SHOOTING);
			}
			else
			{
				setActivity(CMA_WAITING);
			}
		}
		break;
	case CAR_SHOOTING:
		if (CutmanScissors::getInstance()->alive)
		{
			selectActivity(CAR_SHOOTING);
			return;
		}
		setActivity(CMA_SHOOTING);
		break;
	default:
		break;
	}
}

void Cutman::setActivity(CUTMAN_ACTIVITY cutmanActivity)
{
	if (cutmanActivity == CMA_SHOOTING)
	{
		setType(CM_ATTACKING);
		CutmanScissors::getInstance()->alive = true;
		CutmanScissors::getInstance()->scissorsActivity = SCISSORS_ATTACK; // TODO doi ten
		CutmanScissors::getInstance()->x = x;
		CutmanScissors::getInstance()->y = y;
		CutmanScissors::getInstance()->dx = 2 * direction; // TODO Constant
		CutmanScissors::getInstance()->dy = 0;
	}
	if (cutmanActivity == CMA_JUMPING && !ground)
	{
		selectActivity(CAR_JUMPING);
		return;
	}
	this->cutmanActivity = cutmanActivity;
}

void Cutman::setType(CUTMAN_TYPE cutmanType)
{
	this->cutmanType = cutmanType;
}

void Cutman::setAction(int actionValue)
{
	if (actionValue == CM_SHOOTING)
	{
		Enemy::setAction(actionValue);
		setHeight(sprite->anims[actionValue].frames[0].bottom- sprite->anims[actionValue].frames[0].top);
		return;
	}
	if (cutmanAction != actionValue)
	{
		if (actionValue == CM_JUMPING)
		{
			vy = CUTMAN_JUMP_VY;
		}
		cutmanAction = (CUTMAN_ACTION)actionValue;
		this->action = cutmanType* CM_ACTION_COUNT + actionValue;
		setHeight(sprite->anims[action].frames[0].bottom - sprite->anims[action].frames[0].top);
		frameIndex = 0;

	}
}

void Cutman::onCollision(FBox * other, int nx, int ny)
{
	Enemy::onCollision(other, nx, ny);
	if(other->collisionType == CT_GROUND && nx == 1) // TODO lam lop Stone
	{
		setActivity(CMA_JUMPING);
	}
}

Cutman::Cutman()
{
	cutmanType = CM_NON_ATTACKING;
	setActivity(CMA_WAITING);
	cutmanDelay.start(1000);
	direction = Left;
	dx = 0;
	healthPoint = 28;
	CutmanScissors::getInstance()->dx = 0;
	CutmanScissors::getInstance()->cutman = this; //**********
	flickerAction = CM_EXPLOSE;//
	onInjury = false;
	isDisappear = false;
	isRecoil = false;
	injuryDelay.init(RM_INJURY_DELAY_TIME);
	flickeringDelay.init(RM_FLICKER_DELAY_TIME);
}


Cutman::~Cutman()
{
}

void Cutman::updateInjury()
{
	if (onInjury)
	{
		injuryDelay.update();
		flickeringDelay.update();
		if (injuryDelay.isOnTime())
		{
			setAction(RM_INJURE);
		}
		updateFlicker();
		if (flickeringDelay)
		{
			onInjury = false;
			isDisappear = false;
		}
	}
}

void Cutman::onIntersect(FBox * other)
{
	if (other->collisionType == CT_BULLET  && !onInjury)
	{
		int nx; //

		if (getXCenter() > this->getXCenter())
		{
			nx = -1;
		}
		else
			nx = 1;

		this->direction = (Direction)(-nx);
		this->vx = nx * RM_VX_RECOIL;
		//	this->vx = 0; 
		this->vy = RM_VY_RECOIL;
		//this->onStair = false;
		this->ground = false;
		this->isRecoil = true;
		//this->setIsIntersectStair(false);
		//this->setHealth(this->health - attackDamage);
		this->onInjury = true;
		this->flickeringDelay.start();
		this->injuryDelay.start();
	}

	if (other->collisionType == CT_BULLET)
	{
		((RockmanBullet*)other)->canDelete = true;
		setHealthPoint(healthPoint - 1);
		if (healthPoint == 0)
		{
			setDeath();
		}
	}
}