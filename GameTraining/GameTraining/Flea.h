#pragma once
#include "Enemy.h"

class Flea :
	public Enemy
{
public:
	Flea();
	~Flea();

	void update();
};

