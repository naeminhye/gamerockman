#pragma once
#include "MovableObject.h"
#include"Rockman.h"
class Enemy :
	public MovableObject
{
public:
	int defend;
	virtual bool setDefend(int defend);
	void initDirectionFollowRockman(); // TODO: doi ten
	void onIntersect(FBox* other);
	Enemy();
	~Enemy();
};

