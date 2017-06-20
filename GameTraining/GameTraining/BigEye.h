#pragma once
#include "Enemy.h"

/* ENUMERATIONS */
enum BIGEYE_ACTITVITY {
	BIGEYE_WAITING,
	BIGEYE_FLYING
};
#pragma endregion


class BigEye :
	public Enemy
{
public:
	BIGEYE_ACTITVITY bigEyeActivity;
	DelayTime bigEyeDelay;
	float xTarget, yTarget; // toa do x, y cua Rockman

	void initJumpHigh(); // init bay cao
	void initJumpFar(); // init bay xa
	void update();

	/* CONSTRUCTOR & DESTRUCTOR */
	BigEye();
	~BigEye();

};

