#include "RockmanCutBullet.h"
#include "Rockman.h"


void RockmanCutBullet::update()
{
	BaseObject::update();
	float xE, yE; // vi tri cua dan so voi Elip'
	int a = 60, b = 20; // TODO luu constant

	switch (rbcActivity)
	{
	case RBC_GO:
		xE = x - (oldRect.x + a);
		yE = sqrt((1 - ((xE * xE) / (a * a))) * b * b);
		if ((x + dx > oldRect.x + 2 * a && dx > 0) || (x + dx < oldRect.x  && dx < 0))
		{
			dx = -dx;
		}
		if (dx * direction < 0)
		{
			yE = -yE;
			if ((abs(oldRect.x - x) < a && direction > 0) || (abs(oldRect.x - x) > a && direction < 0))
			{
				rbcActivity = RBC_RETURN;
			}

		}
		y = oldRect.y + yE;
		break;
	case RBC_RETURN:
		if (Collision::AABBCheck(this, Rockman::getInstance()))
		{
			alive = false;
			return;
		}
		if (x - Rockman::getInstance()->x != 0)
		{
			dy = dx * (y - Rockman::getInstance()->y) / (x - Rockman::getInstance()->x);
		}
		break;
	default:
		break;
	}
}

RockmanCutBullet::RockmanCutBullet()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_CUTMAN_SCISSORS];
	rbcActivity = RBC_GO;
}


RockmanCutBullet::~RockmanCutBullet()
{
}
