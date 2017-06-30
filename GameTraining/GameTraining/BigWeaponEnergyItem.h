#pragma once
#include "Item.h"
class BigWeaponEnergyItem :
	public Item
{
public:
	//void onIntersect(FBox* other);
	void rockmanBonus();

	/* CONSTRUCTOR & DESTRUCTOR */
	BigWeaponEnergyItem();
	~BigWeaponEnergyItem();

};

