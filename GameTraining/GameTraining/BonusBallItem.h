#pragma once
#include "Item.h"
class BonusBallItem :
	public Item
{
public:
	void onIntersect(FBox* other);
	BonusBallItem();
	~BonusBallItem();
};

