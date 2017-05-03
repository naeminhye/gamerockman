#pragma once
#include "Enemy.h"

enum BIGEYE_ACTITVITY {
	BIGEYE_WAITING,
	BIGEYE_FLYING
};

class BigEye :
	public Enemy
{
public:
	BIGEYE_ACTITVITY bigEyeActivity;
	DelayTime bigEyeDelay;
	float xTarget, yTarget;

	// init bay cao
	void initJumpHigh();
	// init bay xa
	void initJumpFar();


	BigEye();
	~BigEye();
	void update();

};

