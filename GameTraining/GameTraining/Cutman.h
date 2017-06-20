#pragma once
#include "Enemy.h"
#include "Flickable.h"

/* ENUMERATIONS */

enum CUTMAN_ACTIVITY_RAND
{
	// hanh dong cua Cutman la random
	CAR_WAITING,
	CAR_JUMPING,
	CAR_SHOOTING
};

enum CUTMAN_ACTION {
	CM_WAITING,
	CM_RUNNING,
	CM_JUMPING,
	CM_ACTION_COUNT,
	CM_SHOOTING = 6,
	CM_EXPLOSE
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
	public Flickable
{
public:
	DelayTime cutmanDelay;
	CUTMAN_ACTIVITY cutmanActivity;
	CUTMAN_TYPE cutmanType;
	CUTMAN_ACTION cutmanAction;

	// xu li update cac hanh dong cua Cutman
	void updateWaiting();
	void updateRunning();
	void updateJumping();
	void updateShooting();
	void update();

	void onLastFrameAnimation();
	
	bool checkNearRockman(); // kiem tra xem Cutman co dang dung gan Rockman trong mot pham vi cho truoc khong

	void selectActivity(CUTMAN_ACTIVITY_RAND except);
	void setActivity(CUTMAN_ACTIVITY cutmanActivity);
	void setType(CUTMAN_TYPE cutmanType);
	void setAction(int actionValue);

	void onCollision(FBox* other, int nx, int ny);

	bool isRecoil;
	bool onInjury;
	void updateInjury();
	void onIntersect(FBox * other);

	/* CONSTRUCTOR & DESTRUCTOR */
	Cutman();
	~Cutman();

};

