#include "Beak.h"



void Beak::updateBeakSprite()
{
	beakDelay.update();
	switch (beakAction)
	{
	case BEAK_CLOSED:
		//setAction(BEAK_CLOSE);
		this->action = BEAK_CLOSED;
		frameIndex = 0;
		if (beakDelay.isTerminated())
		{
			beakAction = BEAK_OPENING;
			beakDelay.start(TIME_BEAK_CHANGE_STATE);
		}
		return;
	case BEAK_OPENING:
		//setAction(BEAK_OPEN);
		this->action = BEAK_OPENING;
		frameIndex = 0;
		if (beakDelay.isTerminated())
		{
			beakAction = BEAK_SHOOTING;
			beakDelay.start(TIME_BEAK_SHOOTING);
		}
		return;
	case BEAK_SHOOTING:
		//setAction(BEAK_SHOOT);
		this->action = BEAK_SHOOTING;
		frameIndex = 0;
		updateAttack();
		if (beakDelay.isTerminated())
		{
			beakAction = BEAK_CLOSING;
			beakDelay.start(TIME_BEAK_CHANGE_STATE);
		}
		return;
	case BEAK_CLOSING:
		//setAction(BEAK_OPEN);
		this->action = BEAK_CLOSING;
		frameIndex = 0;
		if (beakDelay.isTerminated())
		{
			beakAction = BEAK_CLOSED;
			beakDelay.start(TIME_BEAK_CLOSED);
		}
		return;
	default:
		break;
	}
}

void Beak::update()
{
	Enemy::update();
	updateBeakSprite();
}

void Beak::updateAttack()
{
	if (delay.atTime())
	{
		BeakBullet* bullet = new BeakBullet();
		bullet->dx = direction;
		bullet->dy = 0;
		bullet->x = x;
		bullet->y = y - height / 2 + bullet->height / 2;
	}
}

Beak::Beak()
{
	beakAction = BEAK_CLOSED;
	beakDelay.start(TIME_BEAK_CLOSED);
	direction = Left;
	delay.tickPerFrame = 200;
}


Beak::~Beak()
{
}
