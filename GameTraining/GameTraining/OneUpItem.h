#pragma once
#include "Item.h"

class OneUpItem :
	public Item
{
public:
	void onIntersect(FBox* other);
	
	/* CONSTRUCTOR & DESTRUCTOR */
	OneUpItem();
	~OneUpItem();

};

