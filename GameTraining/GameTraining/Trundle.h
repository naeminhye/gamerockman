#pragma once
#include "MovableObject.h"
#include "Bridge.h"

enum TRUNDLE_ACTION {
	TRUNDLE_NORMAL,
	TRUNDLE_THROW
};

class Trundle :
	public MovableObject
{
public:
	void update();
	void onIntersect(FBox* other);
	void onCollision(FBox* other, int nx, int ny);
	void onLastFrameAnimation();
	Trundle();
	~Trundle();
};

