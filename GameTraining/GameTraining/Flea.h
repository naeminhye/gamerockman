#pragma once
#include "Enemy.h"

enum FLEA_ACTITVITY {
	FLEA_WAITING,
	FLEA_FLYING
};

class Flea :
	public Enemy
{
public:
	FLEA_ACTITVITY fleaActivity;
	DelayTime fleaDelay;
	float xTarget, yTarget;

	// init bay cao
	void initJumpHigh();
	// init bay xa
	void initJumpFar();


	Flea();
	~Flea();
	void update();

};

