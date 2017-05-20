#include "BigLifeEnergyItem.h"



void BigLifeEnergyItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
}

BigLifeEnergyItem::BigLifeEnergyItem()
{
	frameIndex = BIG_LIFE_ENERGY;
}


BigLifeEnergyItem::~BigLifeEnergyItem()
{
}
