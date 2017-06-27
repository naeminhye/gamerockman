#include "BigLifeEnergyItem.h"
#include "Rockman.h"


void BigLifeEnergyItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
	int healthUp = randomFrom(8, 10); // TODO
	Rockman::getInstance()->setHealth(Rockman::getInstance()->health + healthUp);
}

BigLifeEnergyItem::BigLifeEnergyItem()
{
	frameIndex = BIG_LIFE_ENERGY;
}


BigLifeEnergyItem::~BigLifeEnergyItem()
{
}
