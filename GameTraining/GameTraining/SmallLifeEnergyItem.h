#pragma once
#include "Item.h"

class SmallLifeEnergyItem :
	public Item
{
public:
	//void onIntersect(FBox* other);
	void rockmanBonus();

	/* CONSTRUCTOR & DESTRUCTOR */
	SmallLifeEnergyItem();
	~SmallLifeEnergyItem();

};

