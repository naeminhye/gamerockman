#pragma once
#include "MovableObject.h"
class PicketBullet :
	public MovableObject
{
public:
	static List<PicketBullet*>* bullets;
	void deleteBullet();
	void update();
	PicketBullet();
	~PicketBullet();
};

