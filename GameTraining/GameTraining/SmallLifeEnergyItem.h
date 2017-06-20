#pragma once
#include "Item.h"

class SmallLifeEnergyItem :
	public Item
{
public:
	void onIntersect(FBox* other);
	
	/* CONSTRUCTOR & DESTRUCTOR */
	SmallLifeEnergyItem();
	~SmallLifeEnergyItem();

};

