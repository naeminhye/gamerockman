#pragma once
#include "MovableObject.h"

enum ITEM_TYPE
{
	INCREASE_POINT = 12
};

class Item :
	public MovableObject
{
public:
	static List<Item*>* items;
	void release();
	virtual void onIntersect(FBox* other); // goi cuoi cung
	Item();
	virtual ~Item();
};

