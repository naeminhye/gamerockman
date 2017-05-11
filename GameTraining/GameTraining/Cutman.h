#pragma once
#include "Enemy.h"

enum CUTMAN_ACTIVITY_RAND
{
	CAR_WAITING,
	CAR_JUMPING,
	CAR_SHOOTING
};

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
	void updateWaiting();
	void updateRunning();
	void updateJumping();
	void updateShooting();
	void update();
	void onLastFrameAnimation();
	bool checkNearRockman();

	void selectActivity(CUTMAN_ACTIVITY_RAND except);
	void setActivity(CUTMAN_ACTIVITY cutmanActivity);
	void setType(CUTMAN_TYPE cutmanType);
	void setAction(int actionValue);

	void onCollision(FBox* other, int nx, int ny);
	Cutman();
	~Cutman();
};

