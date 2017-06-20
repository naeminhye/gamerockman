#pragma once
#include "Enemy.h"

class SuperCutterBullet :
	public Enemy
{
public:
	static List<SuperCutterBullet*>* bullets;

	bool setHealthPoint(int healthPoint);
	void update();
	void deleteBullet();
	
	/* CONSTRUCTOR & DESTRUCTOR */	
	SuperCutterBullet();
	~SuperCutterBullet();

};

