#pragma once
#include "Item.h"
class BigLifeEnergyItem :
	public Item
{
public:
	void onIntersect(FBox* other);

	/* CONSTRUCTOR & DESTRUCTOR */
	BigLifeEnergyItem();
	~BigLifeEnergyItem();

};

