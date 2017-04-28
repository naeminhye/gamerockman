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

	Flea();
	~Flea();
	void update();
	void onLastFrameAnimation();

};

