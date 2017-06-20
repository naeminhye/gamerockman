#pragma once
#include "BaseObject.h"
class DeathHole :
	public BaseObject
{
public:
	//void onIntersect(FBox* other);
	void onCollision(FBox* other, int nx, int ny);

	/* CONSTRUCTOR & DESTRUCTOR */
	DeathHole();
	~DeathHole();

};

