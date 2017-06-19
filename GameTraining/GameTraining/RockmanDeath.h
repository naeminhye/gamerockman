#pragma once
#include "MovableObject.h"
class RockmanDeath :
	public BaseObject
{
public:
	static List<RockmanDeath*>* deads;
	RockmanDeath();
	~RockmanDeath();
	void updateLocation();
	void update();
	void render();
	void deleteDead();
};

