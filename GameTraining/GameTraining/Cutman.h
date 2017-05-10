#pragma once
#include "Enemy.h"

enum CUTMAN_ACTION {
	CM_WAITING,
	CM_RUNNING,
	CM_JUMPING,
	CM_ACTION_COUNT,
	CM_SHOOTING = 6
};

enum CUTMAN_TYPE {
	CM_NON_ATTACKING,
	CM_ATTACKING
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
	CUTMAN_TYPE cutmanType;
	CUTMAN_ACTION cutmanAction;

	void update();
	void onLastFrameAnimation();

	void setAction(int actionValue);

	Cutman();
	~Cutman();
};

