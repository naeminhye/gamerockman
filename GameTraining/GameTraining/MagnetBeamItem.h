#pragma once
#include "Item.h"
class MagnetBeamItem :
	public Item
{
public:
	//void onIntersect(FBox* other);
	void rockmanBonus();

	/* CONSTRUCTOR & DESTRUCTOR */
	MagnetBeamItem();
	~MagnetBeamItem();


};

