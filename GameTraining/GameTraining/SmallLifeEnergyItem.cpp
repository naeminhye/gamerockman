#include "SmallLifeEnergyItem.h"
#include "Rockman.h"

//
//void SmallLifeEnergyItem::onIntersect(FBox * other)
//{
//	Item::onIntersect(other);
//	
//}

void SmallLifeEnergyItem::rockmanBonus()
{
	int healthUp = SMALL_LIFE_ENERGY_RECOVERY_HP;
	Rockman::getInstance()->setHealth(Rockman::getInstance()->health + healthUp);
}

SmallLifeEnergyItem::SmallLifeEnergyItem()
{
	frameIndex = SMALL_LIFE_ENERGY;
}


SmallLifeEnergyItem::~SmallLifeEnergyItem()
{
}
