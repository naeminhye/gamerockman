#include "Enemy.h"
#include "Death.h"
#include "BonusBallItem.h"
#include "OneUpItem.h"

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
	if(other == Rockman::getInstance() && !Rockman::getInstance()->onInjury)
	{
		int nx; //

		if (getXCenter() > Rockman::getInstance()->getXCenter())
		{
			nx = -1;
		}
		else
			nx = 1;

		Rockman::getInstance()->direction = (Direction)(-nx);
		Rockman::getInstance()->vx = nx*0.1; // TODO LUU CONSTANT
		Rockman::getInstance()->vy = 0.2;
		Rockman::getInstance()->onStair = false;
		Rockman::getInstance()->ground = false;
		Rockman::getInstance()->isRecoil = true;

		Rockman::getInstance()->setHealth(Rockman::getInstance()->health - attackDamage);
		Rockman::getInstance()->onInjury = true;
		Rockman::getInstance()->flickeringDelay.start();
		Rockman::getInstance()->injuryDelay.start();
	}

	if (other->collisionType == CT_BULLET)
	{
		((RockmanBullet*)other)->canDelete = true;
		if (!setHealthPoint(healthPoint - 1))
		{
			alive = false;
			Death* death = new Death();
			death->x = x;
			death->y = y;


			int number = randomFrom(0, 10);
			Item* item;
			if(number == 10)
				item = new OneUpItem();
			else
				item = new BonusBallItem();
			// TODO them item
			item->x = x;
			item->y = y + item->sprite->getHeight(item->action, item->frameIndex);
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
	attackDamage = 1;
}


Enemy::~Enemy()
{
}
