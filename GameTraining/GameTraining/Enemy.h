#pragma once
#include "MovableObject.h"
#include"Rockman.h"
class Enemy :
	public MovableObject
{
public:
	int healthPoint;
	int attackDamage;//
	
	virtual bool setHealthPoint(int healthPoint);
	void initDirectionFollowRockman(); // TODO: doi ten
	void onIntersect(FBox* other);
	Enemy();
	~Enemy();
};

