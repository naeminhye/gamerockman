#pragma once
#include "BaseObject.h"

/* ENUMERATIONS */
enum STAIR_TYPE
{
	STAIR_LEFT = -102, // cau thang co buc tuong chan phia ben trai
	STAIR_RIGHT = -202, // cau thang co buc tuong chan phia ben phai
	STAIR_MIDDLE = -2 // cau thang ko bij tuong chan
};

class Stairs :
	public BaseObject
{
public:

	void onIntersect(FBox* other);
	void onCollision(FBox* other, int nx, int ny);

	/* CONSTRUCTOR & DESTRUCTOR */	
	Stairs();
	~Stairs();

};

