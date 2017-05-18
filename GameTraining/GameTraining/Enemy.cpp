#include "Enemy.h"
#include "Death.h"
#include "IncreasePointItem.h"

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
			Death* death = new Death();
			death->x = x;
			death->y = y;



			Item* item = new IncreasePointItem();
			item->x = x;
			item->y = y;

			item->width = item->sprite->getWidth(item->action, item->frameIndex);
			item->height = item->sprite->getHeight(item->action, item->frameIndex);
			// TODO them item
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
