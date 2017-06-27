#include "Met.h"
#include "BeakBullet.h"


bool Met::setHealthPoint(int healthPoint)
{
	if (healthPoint < this->healthPoint)
	{
		if (action == MET_CLOSE)
		{
			return false;
		}
	}
	Enemy::setHealthPoint(healthPoint);
	return true;
}

void Met::update()
{
	if (!alive)
		return;
	initDirectionFollowRockman();
	metDelay.update();

	int attackDistance = MET_ATTACK_DISTANCE;


	switch (metActivity)
	{
	case MET_WAITING:
		if (!metDelay.isOnTime() && abs(getXCenter() - Rockman::getInstance()->getXCenter())<attackDistance)
		{
			setAction(MET_OPEN);
			metActivity = MET_SHOOTING;
			metDelay.start(MET_DELAYTIME);
			setHeight(sprite->getHeight(MET_OPEN, 0));
			double haftSqrt2 = sqrt(2) / 2;

			BeakBullet* bullet = new BeakBullet();
			bullet->dx = direction ; 
			bullet->dy = 0;
			bullet->x = getXCenter();
			bullet->y = getYCenter();

			bullet = new BeakBullet();
			bullet->dx = direction*haftSqrt2;
			bullet->dy = haftSqrt2;
			bullet->x = getXCenter();
			bullet->y = getYCenter();

			bullet = new BeakBullet();
			bullet->dx = direction*haftSqrt2;
			bullet->dy = -haftSqrt2;
			bullet->x = getXCenter();
			bullet->y = getYCenter();
		}

		break;
	case MET_SHOOTING:
		if (metDelay.isTerminated())
		{
			setHeight(sprite->getHeight(MET_CLOSE, 0));
			setAction(MET_CLOSE);
			metActivity = MET_WAITING;
			metDelay.start(MET_DELAYTIME);
		}
		break;
	default:
		break;
	}

}

void Met::init()
{
	setHeight(sprite->getHeight(MET_CLOSE, 0));
}


Met::Met()
{
	metActivity = MET_WAITING;
	//setHeight(sprite->getHeight(MET_CLOSE, 0));
	metDelay.start(MET_DELAYTIME);
	healthPoint = MET_HEALTH_POINTS;
	attackDamage = MET_ATTACK_DAMAGE;
}


Met::~Met()
{
}
