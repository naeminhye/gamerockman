#include "BigLifeEnergyItem.h"
#include "Rockman.h"


//void BigLifeEnergyItem::onIntersect(FBox * other)
//{
//	Item::onIntersect(other);
//	
//}

void BigLifeEnergyItem::rockmanBonus()
{
	int healthUp = BIG_LIFE_ENERGY_RECOVERY_HP;
	Rockman::getInstance()->setHealth(Rockman::getInstance()->health + healthUp);
}

BigLifeEnergyItem::BigLifeEnergyItem()
{
	frameIndex = BIG_LIFE_ENERGY;
}


BigLifeEnergyItem::~BigLifeEnergyItem()
{
}
