#include "Picket.h"
#include "PicketBullet.h"


Picket::Picket()
{
	picketActivity = PICKET_WAITING;
	picketDelay.start(PICKET_DELAYTIME);
	delay.tickPerFrame = PICKET_DELAYTIME_FRAME; 
	attackDamage = 3;
	healthPoint = 10;
}


Picket::~Picket()
{

}

void Picket::update()
{
	picketDelay.update();
	picketbulletDelay.update();
	initDirectionFollowRockman();
	PicketBullet* bullet;
	float xTarget, yTarget;
	double delta;
	Enemy::update();
	switch (picketActivity)
	{
	case PICKET_WAITING:
		if (picketDelay.isTerminated())
		{
			setAction(PICKET_SHOOT);
			picketActivity = PICKET_SHOOTING;
			picketDelay.start(PICKET_DELAYTIME);

		}
		break;
	case PICKET_SHOOTING:
		if (picketbulletDelay.isTerminated())
		{
			bullet = new PicketBullet();

			xTarget = Rockman::getInstance()->x;
			yTarget = Rockman::getInstance()->y;

			bullet->x = x;
			bullet->y = y;
			if (getXCenter() > Rockman::getInstance()->getXCenter())
			{
				bullet->direction = Left;
			}
			else
			{
				bullet->direction = Right;
			}
			bullet->vy = PICKET_BULLET_VY; 

			delta = bullet->vy*bullet->vy - 4 * bullet->ay*(y - yTarget);

			bullet->vx = (xTarget - x) *  ay / (-bullet->vy - sqrt(delta));


			picketbulletDelay.start(PICKET_BULLET_V);
		}
		if (picketDelay.isTerminated())
		{
			setAction(PICKET_WAIT);
			picketActivity = PICKET_WAITING;
			picketDelay.start(PICKET_DELAYTIME);

		}
		break;
	default:
		break;
	}
	
}
