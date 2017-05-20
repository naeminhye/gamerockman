#include "BigWeaponEnergyItem.h"



void BigWeaponEnergyItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
}

BigWeaponEnergyItem::BigWeaponEnergyItem()
{
	frameIndex = BIG_WEAPON_ENERGY;
}


BigWeaponEnergyItem::~BigWeaponEnergyItem()
{
}
