#include "Enemy.h"



bool Enemy::setDefend(int defend)
{
	if (defend > 0)
	{
		this->defend = defend;
		return true;
	}
	defend = 0;
	return false;
}

void Enemy::initDirectionFollowRockman()
{
	if (Rockman::getInstance()->xCenter() > this->xCenter())
		direction = Right;
	else
		direction = Left;
}

void Enemy::onIntersect(FBox * other)
{
	if (other->collisionType == CT_BULLET)
	{
		((RockmanBullet*)other)->canDelete = true;
		if (!setDefend(defend - 1))
		{
			alive = false;
		}
	}
}

Enemy::Enemy()
{
	collisionType = CT_ENEMY;
	defend = 2;
}


Enemy::~Enemy()
{
}
