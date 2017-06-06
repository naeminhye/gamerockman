#pragma once
#include "BaseObject.h"
class Spike :
	public BaseObject
{
public:
	void onCollision(FBox* other, int nx, int ny);
	Spike();
	~Spike();
};

