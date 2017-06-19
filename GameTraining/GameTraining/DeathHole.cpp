#include "DeathHole.h"
#include "Rockman.h"


//void DeathHole::onIntersect(FBox * other)
//{
//	
//}

void DeathHole::onCollision(FBox * other, int nx, int ny)
{
	if (other == Rockman::getInstance())
	{
		Rockman::getInstance()->setHealth(0);
	}
}

DeathHole::DeathHole()
{
	//collisionType = CT_ITEM;
}


DeathHole::~DeathHole()
{
}
