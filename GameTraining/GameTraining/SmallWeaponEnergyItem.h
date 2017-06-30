#pragma once
#include "Item.h"

class SmallWeaponEnergyItem :
	public Item
{
public:
	//void onIntersect(FBox* other);
	void rockmanBonus();

	/* CONSTRUCTOR & DESTRUCTOR */
	SmallWeaponEnergyItem();
	~SmallWeaponEnergyItem();

};

