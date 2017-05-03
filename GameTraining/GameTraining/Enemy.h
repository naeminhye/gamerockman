#pragma once
#include "MovableObject.h"
#include"Rockman.h"
class Enemy :
	public MovableObject
{
public:

	void initDirectionFollowRockman(); // TODO: doi ten
	Enemy();
	~Enemy();
};

