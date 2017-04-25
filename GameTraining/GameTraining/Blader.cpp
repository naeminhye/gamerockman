#include "Blader.h"



void Blader::update()
{
	switch (bladerActivity)
	{
	case BLADER_PREPARE:
		if (Rockman::getInstance()->xCenter() > xCenter())
			direction = Right;
		else
			direction = Left;
		dx = 2 * direction;
		if (abs(this->xCenter() - Rockman::getInstance()->xCenter()) <= BLADER_FIND_ROCKMAN_DISTANCE)
		{
			bladerActivity = BLADER_ATTACK;
			xTarget = Rockman::getInstance()->x;
			yTarget = Rockman::getInstance()->y;
			//if (Rockman::getInstance()->y > y)
			//	dy = BLADER_ATTACK_DY;
			//else
			//	dy = -BLADER_ATTACK_DY;
			//
			//dx = ((xTarget - x) / (yTarget - y)) * dy;

			float m = (xTarget - x) / (yTarget - y);

			float k = 3;

			dy =  k / sqrt(m*m + 1);

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
		if ((this->y + dy < yTarget && (yTarget>y) ) || (this->y + dy > yTarget && (yTarget<y)))
		{
			dy = -dy;
		}
		if (this->y + dy > oldRect.y)
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
	//auto rockman = Rockman::getInstance();
	//if (other == rockman)
	//{
	//	// xu li va cham Rockman voi Blader
	//}
}

Blader::Blader()
{
	bladerActivity = BLADER_PREPARE;
	dy = 0;
}


Blader::~Blader()
{
}
