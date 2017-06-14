#include "SmallLifeEnergyItem.h"
#include "Rockman.h"


void SmallLifeEnergyItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
	int healthUp = randomFrom(2, 4);
	Rockman::getInstance()->setHealth(Rockman::getInstance()->health + healthUp);
}

SmallLifeEnergyItem::SmallLifeEnergyItem()
{
	frameIndex = SMALL_LIFE_ENERGY;
}


SmallLifeEnergyItem::~SmallLifeEnergyItem()
{
}
