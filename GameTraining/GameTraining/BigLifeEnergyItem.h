#pragma once
#include "Item.h"
class BigLifeEnergyItem :
	public Item
{
public:
	//void onIntersect(FBox* other);
	void rockmanBonus();

	/* CONSTRUCTOR & DESTRUCTOR */
	BigLifeEnergyItem();
	~BigLifeEnergyItem();

};

