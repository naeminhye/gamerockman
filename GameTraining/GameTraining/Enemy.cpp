#include "Enemy.h"



bool Enemy::setHealthPoint(int healthPoint)
{
	if (healthPoint > 0)
	{
		this->healthPoint = healthPoint;
		return true;
	}
	healthPoint = 0;
	return false;
}

void Enemy::initDirectionFollowRockman()
{
	if (Rockman::getInstance()->getXCenter() > this->getXCenter())
		direction = Right;
	else
		direction = Left;
}

void Enemy::onIntersect(FBox * other)
{
	if (other->collisionType == CT_BULLET)
	{
		((RockmanBullet*)other)->canDelete = true;
		if (!setHealthPoint(healthPoint - 1))
		{
			alive = false;
		}
	}
}

Enemy::Enemy()
{
	collisionType = CT_ENEMY;
	healthPoint = 2;
}


Enemy::~Enemy()
{
}
