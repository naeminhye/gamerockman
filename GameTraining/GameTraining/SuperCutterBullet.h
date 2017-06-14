#pragma once
#include "Enemy.h"
class SuperCutterBullet :
	public Enemy
{
public:
	static List<SuperCutterBullet*>* bullets;
	bool setHealthPoint(int healthPoint);// ko lam gi het => dan ko chet
	void update();
	void deleteBullet();
	SuperCutterBullet();
	~SuperCutterBullet();
};

