#pragma once
#include "Item.h"

class YashichiItem :
	public Item
{
public:
	void onIntersect(FBox* other);

	/* CONSTRUCTOR & DESTRUCTOR */	
	YashichiItem();
	~YashichiItem();

};

