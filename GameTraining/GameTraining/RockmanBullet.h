#pragma once
#include"MovableObject.h"
#include"MGMCamera.h"

class RockmanBullet : public MovableObject
{
public:
	static List<RockmanBullet*>* bullets;
	void update();

	bool canDelete;

	RockmanBullet();
	~RockmanBullet();

	void deleteBullet();
};

