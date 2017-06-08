#pragma once
#include "Enemy.h"
class BeakBullet :
	public Enemy
{
public:
	static List<BeakBullet*>* bullets;
	bool setHealthPoint(int healthPoint);// ko lam gi het => dan ko chet
	void update();
	void deleteBullet();
	BeakBullet();
	~BeakBullet();
};

