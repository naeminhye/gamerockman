#pragma once
#include "MovableObject.h"
#include "Bridge.h"

/* ENUMERATIONS */
enum TRUNDLE_ACTION {
	TRUNDLE_NORMAL,
	TRUNDLE_THROW
};

class Trundle :
	public MovableObject
{
public:
	void update();
	void updateMove();
	void onIntersect(FBox* other);
	void onCollision(FBox* other, int nx, int ny);
	void onLastFrameAnimation();

	/* CONSTRUCTOR & DESTRUCTOR */	
	Trundle();
	~Trundle();

};

