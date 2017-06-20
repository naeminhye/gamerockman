#pragma once
#include "MovableObject.h"

/* ENUMERATIONS */
enum ITEM_TYPE
{
	// cac loai Items xuat hien sau khi Enemy chet
	SMALL_LIFE_ENERGY,
	SMALL_WEAPON_ENERGY,
	BIG_LIFE_ENERGY,
	BIG_WEAPON_ENERGY = 4,
	MAGNET_BEAM = 10,
	YASHICHI = 11,
	BONUS_BALL = 12,
	ONE_UP = 25
};

class Item :
	public MovableObject
{
public:
	static List<Item*>* items;
	void release();
	virtual void onIntersect(FBox* other); // goi cuoi cung

	/* CONSTRUCTOR & DESTRUCTOR */
	Item();
	virtual ~Item();

};

