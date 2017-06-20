#pragma once
#include "MovableObject.h"
class RockmanDeath :
	public BaseObject
{
public:
	static List<RockmanDeath*>* deads;

	void updateLocation();
	void update();
	void render();
	void deleteDead();

	/* CONSTRUCTOR & DESTRUCTOR */
	RockmanDeath();
	~RockmanDeath();

};

