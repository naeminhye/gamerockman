#pragma once
#include "Enemy.h"
class PicketBullet :
	public Enemy
{
public:
	static List<PicketBullet*>* bullets;
	bool setHealthPoint(int healthPoint);// ko lam gi het => dan ko chet
	void deleteBullet();
	void update();
	PicketBullet();
	~PicketBullet();
};

