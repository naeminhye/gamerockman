#include "SmallWeaponEnergyItem.h"



void SmallWeaponEnergyItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
}

SmallWeaponEnergyItem::SmallWeaponEnergyItem()
{
	frameIndex = SMALL_WEAPON_ENERGY;
}


SmallWeaponEnergyItem::~SmallWeaponEnergyItem()
{
}
