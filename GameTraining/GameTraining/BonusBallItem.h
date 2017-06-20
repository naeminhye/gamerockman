#pragma once
#include "Item.h"
class BonusBallItem :
	public Item
{
public:
	void onIntersect(FBox* other);

	/* CONSTRUCTOR & DESTRUCTOR */
	BonusBallItem();
	~BonusBallItem();

};

