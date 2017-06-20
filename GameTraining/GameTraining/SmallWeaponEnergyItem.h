#pragma once
#include "Item.h"

class SmallWeaponEnergyItem :
	public Item
{
public:
	void onIntersect(FBox* other);
	
	/* CONSTRUCTOR & DESTRUCTOR */
	SmallWeaponEnergyItem();
	~SmallWeaponEnergyItem();

};

