#pragma once
#include "Item.h"

class YashichiItem :
	public Item
{
public:
	//void onIntersect(FBox* other);
	void rockmanBonus();

	/* CONSTRUCTOR & DESTRUCTOR */	
	YashichiItem();
	~YashichiItem();

};

