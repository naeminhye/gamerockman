#pragma once
#include "Item.h"

class OneUpItem :
	public Item
{
public:
	//void onIntersect(FBox* other);
	void rockmanBonus();

	/* CONSTRUCTOR & DESTRUCTOR */
	OneUpItem();
	~OneUpItem();

};

