#pragma once
#include "MovableObject.h"
class BeakBullet :
	public MovableObject
{
public:
	static List<BeakBullet*>* bullets;
	void update();
	void deleteBullet();
	BeakBullet();
	~BeakBullet();
};

