#pragma once
#include "Item.h"
class YashichiItem :
	public Item
{
public:
	void onIntersect(FBox* other);
	YashichiItem();
	~YashichiItem();
};

