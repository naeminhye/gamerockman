#pragma once
#include "MovableObject.h"
class SuperCutterBullet :
	public MovableObject
{
public:
	static List<SuperCutterBullet*>* bullets;
	void update();
	void deleteBullet();
	SuperCutterBullet();
	~SuperCutterBullet();
};

