#pragma once
#include "Item.h"
class BigWeaponEnergyItem :
	public Item
{
public:
	void onIntersect(FBox* other);

	/* CONSTRUCTOR & DESTRUCTOR */
	BigWeaponEnergyItem();
	~BigWeaponEnergyItem();

};

