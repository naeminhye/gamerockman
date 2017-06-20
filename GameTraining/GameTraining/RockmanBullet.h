#pragma once
#include"MovableObject.h"
#include"Camera.h"

class RockmanBullet : public MovableObject
{
public:
	static List<RockmanBullet*>* bullets;
	bool canDelete;
	
	virtual void update();
	void deleteBullet();

	/* CONSTRUCTOR & DESTRUCTOR */
	RockmanBullet();
	~RockmanBullet();

};

