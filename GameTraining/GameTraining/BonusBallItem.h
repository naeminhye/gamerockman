#pragma once
#include "Item.h"
class BonusBallItem :
	public Item
{
public:
	//void onIntersect(FBox* other);
	void rockmanBonus();

	/* CONSTRUCTOR & DESTRUCTOR */
	BonusBallItem();
	~BonusBallItem();

};

