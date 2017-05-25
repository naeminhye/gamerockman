#pragma once
#include"MovableObject.h"
#include"MGMCamera.h"

class RockmanBullet : public MovableObject
{
public:
	static List<RockmanBullet*>* bullets;
	virtual void update();

	bool canDelete;

	RockmanBullet();
	~RockmanBullet();

	void deleteBullet();
};

