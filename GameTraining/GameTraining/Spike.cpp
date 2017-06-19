#include "Spike.h"
#include "Rockman.h"


void Spike::onCollision(FBox * other, int nx, int ny)
{
	if (other == Rockman::getInstance())
	{
		Rockman::getInstance()->setHealth(0);
	}
}

Spike::Spike()
{
	//collisionType = CT_ITEM;
}


Spike::~Spike()
{
}
