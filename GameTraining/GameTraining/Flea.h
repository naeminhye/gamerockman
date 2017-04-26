#pragma once
#include "Enemy.h"

enum FLEA_ACTIVITY {
	FLEA_STAND,
	FLEA_FLY
};

class Flea :
	public Enemy
{
public:
	Flea();
	~Flea();

	void updateLocation();
};

