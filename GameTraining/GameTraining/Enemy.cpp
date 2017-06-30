#include "Enemy.h"
#include "Death.h"
#include "BonusBallItem.h"
#include "OneUpItem.h"
#include "BigLifeEnergyItem.h"
#include "SmallLifeEnergyItem.h"
#include "SmallWeaponEnergyItem.h"
#include "BigWeaponEnergyItem.h"
#include"KEY.h"

void Enemy::selectItem()
{
	while (true)
	{
		int r = randomFrom(0, itemCount);

		int sum = 0;

		for (int i = 0; i < 6; i++)
		{
			sum += itemDecisionTable[i];
			if (sum > r)
			{
				itemDecision = (ITEM_DECISION)i;
				return;
			}
		}
	}
}

bool Enemy::setHealthPoint(int healthPoint)
{
	if (healthPoint > 0)
	{
		this->healthPoint = healthPoint;
		return false;
	}
	this->healthPoint = 0;
	return true;
}

void Enemy::setDeath()
{
	GameSound::getInstance()->play(SOUND_ENEMY_DAMAGE, false);
	
	alive = false;
	Death* death = new Death();
	death->x = x;
	death->y = y;

	selectItem();

	//int number = randomFrom(0, 15);
	Item* item;
	switch (itemDecision)
	{
	case BONUS_BALL_POINTS_D:
		item = new BonusBallItem();
		break;
	case SMALL_LIFE_ENERGY_D:
		item = new SmallLifeEnergyItem();
		break;
	case BIG_LIFE_ENERGY_D:
		item = new BigLifeEnergyItem();
		break;
	case SMALL_WEAPON_D:
		item = new SmallWeaponEnergyItem();
		break;
	case BIG_WEAPON_D:
		item = new BigWeaponEnergyItem();
		break;
	case ONE_UP_LIFE_D:
		item = new OneUpItem();
		break;
	default:
		item = new BonusBallItem();
		break;
	}
	/*if (number == 0)
		item = new OneUpItem();
	else if (number == 1)
		item = new BigLifeEnergyItem();
	else if (number == 2 || number == 3)
		item = new SmallLifeEnergyItem();
	else
		item = new BonusBallItem();*/
	// TODO them item
	item->x = x;
	item->y = y + item->sprite->getHeight(item->action, item->frameIndex);
	item->width = item->sprite->getWidth(item->action, item->frameIndex);
	item->height = item->sprite->getHeight(item->action, item->frameIndex);
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
				Rockman::getInstance()->setScores(Rockman::getInstance()->scores + points);
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
	itemDecisionTable = new int[6];
	itemDecisionTable[SMALL_LIFE_ENERGY_D] = SMALL_LIFE_ENERGY_R;
	itemDecisionTable[BIG_LIFE_ENERGY_D] = BIG_LIFE_ENERGY_R;
	itemDecisionTable[SMALL_WEAPON_D] = SMALL_WEAPON_R;
	itemDecisionTable[BIG_WEAPON_D] = BIG_WEAPON_R;
	itemDecisionTable[ONE_UP_LIFE_D] = ONE_UP_LIFE_R;
	itemDecisionTable[BONUS_BALL_POINTS_D] = BONUS_BALL_POINTS_R;
	itemCount = SMALL_LIFE_ENERGY_R + BIG_LIFE_ENERGY_R + SMALL_WEAPON_R + BIG_WEAPON_R + ONE_UP_LIFE_R + ONE_UP_LIFE_R;


}			  


Enemy::~Enemy()
{
}
