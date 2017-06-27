#include "Enemy.h"
#include "Death.h"
#include "BonusBallItem.h"
#include "OneUpItem.h"
#include "BigLifeEnergyItem.h"
#include "SmallLifeEnergyItem.h"
#include"KEY.h"

bool Enemy::setHealthPoint(int healthPoint)
{
	if (healthPoint > 0)
	{
		this->healthPoint = healthPoint;
		return true;
	}
	this->healthPoint = 0;
	return false;
}

void Enemy::setDeath()
{
	GameSound::getInstance()->play(SOUND_ENEMY_DAMAGE, false);
	
	alive = false;
	Death* death = new Death();
	death->x = x;
	death->y = y;

	int number = randomFrom(0, 15);
	Item* item;
	if (number == 0)
		item = new OneUpItem();
	else if (number == 1)
		item = new BigLifeEnergyItem();
	else if (number == 2 || number == 3)
		item = new SmallLifeEnergyItem();
	else
		item = new BonusBallItem();
	// TODO them item
	item->x = x;
	item->y = y + item->sprite->getHeight(item->action, item->frameIndex);
	item->width = item->sprite->getWidth(item->action, item->frameIndex);
	item->height = item->sprite->getHeight(item->action, item->frameIndex);
	// TODO them item
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
		GameSound::getInstance()->play(SOUND_MEGAMAN_DAMAGE, false);

		int nx; //

		if (getXCenter() > Rockman::getInstance()->getXCenter())
		{
			nx = -1;
		}
		else
			nx = 1;

		Rockman::getInstance()->direction = (Direction)(-nx);
		Rockman::getInstance()->vx = nx * RM_VX_RECOIL;
	//	Rockman::getInstance()->vx = 0; 
		Rockman::getInstance()->vy = RM_VY_RECOIL; 
		Rockman::getInstance()->onStair = false;
		Rockman::getInstance()->ground = false;
		Rockman::getInstance()->isRecoil = true;
		Rockman::getInstance()->setIsIntersectStair ( false);
		Rockman::getInstance()->setHealth(Rockman::getInstance()->health - attackDamage);
		Rockman::getInstance()->onInjury = true;
		Rockman::getInstance()->flickeringDelay.start();
		Rockman::getInstance()->injuryDelay.start();
		KEY::getInstance()->isUpDown = false;
		KEY::getInstance()->isDownDown = false;
	}

	if (other->collisionType == CT_BULLET)
	{
		((RockmanBullet*)other)->canDelete = true;
		if (setHealthPoint(healthPoint - 1))
		{
			if (healthPoint == 0)
			{
				setDeath();
			}
		}
		else
		{
			GameSound::getInstance()->play(SOUND_DINK);
		}
	}
}

void Enemy::init()
{
	maxHealth = healthPoint;
	setHealthPoint(maxHealth);
}

void Enemy::restoreLocation()
{
	MovableObject::restoreLocation();
	if(!alive)
		alive = true;
	setHealthPoint(maxHealth);
	// TODO reset healthPoint
}

Enemy::Enemy()
{
	collisionType = CT_ENEMY;
	healthPoint = ENEMY_DEFAULT_HEALTH_POINTS;
	attackDamage = ENEMY_DEFAULT_ATTACK_DAMAGE;
	points = ENEMY_DEFAULT_POINTS;
}


Enemy::~Enemy()
{
}
