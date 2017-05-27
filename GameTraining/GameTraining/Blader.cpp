#include "Blader.h"



void Blader::update()
{
	switch (bladerActivity)
	{
	case BLADER_PREPARE:
		if (Rockman::getInstance()->getXCenter() > getXCenter())
			direction = Right;
		else
			direction = Left;
		dx = 2 * direction;
		if (abs(this->getXCenter() - Rockman::getInstance()->getXCenter()) <= BLADER_FIND_ROCKMAN_DISTANCE)
		{
			bladerActivity = BLADER_ATTACK;
			xTarget = Rockman::getInstance()->x;
			yTarget = Rockman::getInstance()->y;

			float m = (xTarget - x) / (yTarget - y);

			float k = BLADER_ATTACK_DY;

			dy = k / sqrt(m * m + 1);

			if (yTarget > y)
			{
				dy = abs(dy);
			}
			else
				dy = -abs(dy);

			dx = m*dy;


		}
		break;
	case BLADER_ATTACK:
		if ((this->y + dy < yTarget && (oldRect.y > yTarget)) || (this->y + dy > yTarget && (oldRect.y < yTarget)))
		{
			dy = -dy;
		}
		if ((this->y + dy > oldRect.y && oldRect.y > yTarget) || (this->y + dy < oldRect.y && oldRect.y < yTarget))
		{
			dy = 0;
			bladerActivity = BLADER_PREPARE;
		}
		break;
	default:
		break;
	}
}

void Blader::onCollision(FBox * other, int nx, int ny)
{
	
}

Blader::Blader()
{
	bladerActivity = BLADER_PREPARE;
	dy = 0;
	healthPoint = 1;
	attackDamage = 3;
}


Blader::~Blader()
{
}
