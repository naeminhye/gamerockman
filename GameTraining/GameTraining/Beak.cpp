#include "Beak.h"

void Beak::updateLocation()
{
}

void Beak::update()
{
	Enemy::update();
	beakDelay.update();
	switch (beakActivity)
	{
	case BEAK_WAITING:
		if (beakDelay.isTerminated())
		{
			beakActivity = BEAK_OPENING;
			pauseAnimation = false;
			setAction(BEAK_OPEN);
		}
		break;
	case BEAK_OPENING:
		break;
	case BEAK_SHOOTING:
		if (updateAttack())
		{
			beakActivity = BEAK_CLOSING;
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

bool Beak::updateAttack()
{
	if (!bulletDelay.isOnTime() && this->alive)
	{
		BeakBullet* bullet = new BeakBullet();
		bullet->dx = BEAK_BULLET_VELOCITY*direction;
		if (direction == Left)
		{
			bullet->x = x;

		}
		else
		{
			bullet->x = x + sprite->anims[action].frames[frameIndex].right - sprite->anims[action].frames[frameIndex].left - 5;
		}
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
	if (beakActivity == BEAK_OPENING)
	{
		pauseAnimation = true;
		beakDelay.start(TIME_BEAK_SHOOTING);
		beakActivity = BEAK_SHOOTING;
		bulletLocation = TOP;
		frameIndex = 3;
	}
	else if (beakActivity == BEAK_CLOSING)
	{
		pauseAnimation = true;
		beakDelay.start(TIME_BEAK_CLOSED);
		beakActivity = BEAK_WAITING;
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
	beakActivity = BEAK_WAITING;
	direction = Left;
	bulletDelay.init(BEAK_BULLET_DELAY);
	pauseAnimation = true;
	beakDelay.start(TIME_BEAK_CLOSED);
	healthPoint = 1;
	attackDamage = 0; // TODO dan cua Beak moi co attackDamage = 1
}


Beak::~Beak()
{
}
