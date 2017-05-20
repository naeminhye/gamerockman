#include "SmallLifeEnergyItem.h"



void SmallLifeEnergyItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
}

SmallLifeEnergyItem::SmallLifeEnergyItem()
{
	frameIndex = SMALL_LIFE_ENERGY;
}


SmallLifeEnergyItem::~SmallLifeEnergyItem()
{
}
