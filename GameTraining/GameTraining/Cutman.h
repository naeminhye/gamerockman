#pragma once
#include "Enemy.h"
#include "Flickable.h"

enum CM_NONATTACKING_RANDOM_ACTIVITY {
	CMNRA_WAIT,
	CMNRA_SHOOT,
	CMNRA_RUN,
	CMNRA_JUMP_SHORT,
	CMNRA_JUMP_LONG,
	CMNRA_COUNT
};

enum CM_ATTACKING_RANDOM_ACTIVITY {
	CMRA_WAIT,
	CMRA_RUN,
	CMRA_JUMP_SHORT,
	CMRA_JUMP_LONG,
	CMRA_COUNT
};

extern int CM_WAIT_R;
extern int CM_RUN_R;
extern int CM_JUMP_SHORT_R;
extern int CM_JUMP_LONG_R;

extern int CM_NON_WAIT_R;
extern int CM_NON_SHOOT_R;
extern int CM_NON_RUN_R;
extern int CM_NON_JUMP_SHORT_R;
extern int CM_NON_JUMP_LONG_R;

enum CUTMAN_TYPE {
	CM_NON_ATTACKING,
	CM_ATTACKING
};

enum CUTMAN_ACTION {
	CM_WAITING,
	CM_RUNNING,
	CM_JUMPING,
	CM_ACTION_COUNT,
	CM_SHOOTING = 6,
	CM_EXPLOSE
};
///* ENUMERATIONS */
//
//enum CUTMAN_ACTIVITY_RAND
//{
//	// hanh dong cua Cutman la random
//	CAR_WAITING,
//	CAR_JUMPING,
//	CAR_SHOOTING
//};
//
//
//enum CUTMAN_TYPE {
//	CM_NON_ATTACKING,
//	CM_ATTACKING
//};
//
//enum CUTMAN_ACTIVITY {
//	CMA_WAITING,
//	CMA_RUNNING,
//	CMA_SHOOTING,
//	CMA_JUMPING
//};

class Cutman : public Enemy
{
public:

	int* cmNonAttackTable;
	int* cmAttackTable;
	bool canSelect;
	int randNonAttackCount;
	int randAttackCount;

	CM_ATTACKING_RANDOM_ACTIVITY attackSelection;
	CM_NONATTACKING_RANDOM_ACTIVITY nonAttackSelection;

	void selectAttack();
	void selectNonAttack();

	CUTMAN_TYPE cutmanType;
	CUTMAN_ACTION cutmanAction;

	DelayTime cutmanDelay;
	void onLastFrameAnimation();

	void onCollision(FBox* other, int nx, int ny);

	//DelayTime cutmanDelay;
	//CUTMAN_ACTIVITY cutmanActivity;
	//CUTMAN_TYPE cutmanType;
	//CUTMAN_ACTION cutmanAction;

	//// xu li update cac hanh dong cua Cutman
	//void updateWaiting();
	//void updateRunning();
	//void updateJumping();
	//void updateShooting();
	//void update();

	//void onLastFrameAnimation();
	//
	//bool checkNearRockman(); // kiem tra xem Cutman co dang dung gan Rockman trong mot pham vi cho truoc khong

	//void selectActivity(CUTMAN_ACTIVITY_RAND except);
	//void setActivity(CUTMAN_ACTIVITY cutmanActivity);
	//void setType(CUTMAN_TYPE cutmanType);
	//void setAction(int actionValue);

	//void onCollision(FBox* other, int nx, int ny);

	//bool isRecoil;
	//bool onInjury;
	//void updateInjury();
	//void onIntersect(FBox * other);

	/* CONSTRUCTOR & DESTRUCTOR */

	void update();

	void updateNonAttacking();
	void updateAttacking();

	void setAction(int actionValue);

	Cutman();
	~Cutman();

};

