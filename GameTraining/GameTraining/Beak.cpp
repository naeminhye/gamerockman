#include "Beak.h"



void Beak::updateBeakSprite()
{
	beakDelay.update();
	switch (beakAction)
	{
	case BEAK_WAITING:
		if (beakDelay.isTerminated())
		{
			beakAction = BEAK_OPENING;
			pauseAnimation = false;
			setAction(BEAK_OPEN);
		}
		break;
	case BEAK_OPENING:
		break;
	case BEAK_SHOOTING:
		if(updateAttack())
		{
			beakAction = BEAK_CLOSING;
			pauseAnimation = false;
			setAction(BEAK_CLOSE);
		}
		break;
	case BEAK_CLOSING:
		break;
	default:
		break;
	}
}

void Beak::updateLocation()
{
}

void Beak::update()
{
	Enemy::update();
	updateBeakSprite();
}

bool Beak::updateAttack()
{
	if (!bulletDelay.isOnTime())
	{
		BeakBullet* bullet = new BeakBullet();
		bullet->dx = BEAK_BULLET_VELOCITY*direction;
		bullet->x = x;
		bullet->y = y - height / 2 + bullet->height / 2;
		switch (bulletLocation)
		{
		case TOP:
			bullet->dy = BEAK_BULLET_VELOCITY;
			bulletLocation = MIDDLE_TOP;
			break;
		case MIDDLE_TOP:
			bullet->dy = BEAK_BULLET_VELOCITY*tan(TAN_5_TO_RAD);
			bulletLocation = MIDDLE_BOTTOM;
			break;
		case MIDDLE_BOTTOM:
			bullet->dy = -BEAK_BULLET_VELOCITY*tan(TAN_5_TO_RAD);
			bulletLocation = BOTTOM;
			break;
		case BOTTOM:
			bullet->dy = -BEAK_BULLET_VELOCITY;
			return true;
		default:
			break;
		}
		bulletDelay.start();
	}
	bulletDelay.update();
	return false;
}

void Beak::onLastFrameAnimation()
{
	if (beakAction == BEAK_OPENING)
	{
		pauseAnimation = true;
		beakDelay.start(TIME_BEAK_SHOOTING);
		beakAction = BEAK_SHOOTING;
		bulletLocation = TOP;
		frameIndex = 3;
	}
	else if (beakAction == BEAK_CLOSING)
	{
		pauseAnimation = true;
		beakDelay.start(TIME_BEAK_CLOSED);
		beakAction = BEAK_WAITING;
		frameIndex = 3;
	}
}

void Beak::init()
{
	if (this->id == BEAK_LEFT)
	{
		direction = Left;
	}
	else if (this->id == BEAK_RIGHT)
	{
		direction = Right;
	}
}

Beak::Beak()
{
	beakAction = BEAK_WAITING;
	direction = Left;
	bulletDelay.init(BEAK_BULLET_DELAY);
	pauseAnimation = true;
	beakDelay.start(TIME_BEAK_CLOSED);
}


Beak::~Beak()
{
}
