#pragma once
#include "Item.h"
class IncreasePointItem :
	public Item
{
public:
	void onIntersect(FBox* other);
	IncreasePointItem();
	~IncreasePointItem();
};

