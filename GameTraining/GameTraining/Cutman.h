#pragma once
#include "Enemy.h"

enum CUTMAN_ACTION {
	CM_WAITING_WITH_KNIFE,
	CM_RUNNING_WITH_KNIFE,
	CM_JUMPING_WITH_KNIFE,
	CM_SHOOTING,
	CM_WAITING,
	CM_RUNNING,
	CM_JUMPING
};

enum CUTMAN_ACTIVITY {
	CMA_WAITING,
	CMA_RUNNING,
	CMA_SHOOTING,
	CMA_JUMPING
};

class Cutman :
	public Enemy
{
public:
	DelayTime cutmanDelay;
	CUTMAN_ACTIVITY cutmanActivity;

	void update();
	void onLastFrameAnimation();
	Cutman();
	~Cutman();
};

