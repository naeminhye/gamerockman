#include "BigEye.h"



void BigEye::initJumpHigh()
{
	vy = BIGEYE_JUMP_HIGH_VY;
	vx = direction * BIGEYE_JUMP_HIGH_VX;
}

void BigEye::initJumpFar()
{
	vy = BIGEYE_JUMP_FAR_VY;
	vx = direction * BIGEYE_JUMP_FAR_VX;
}

BigEye::BigEye()
{
	bigEyeDelay.init(BIGEYE_DELAYTIME); 
	bigEyeDelay.start();
	setAction(BIGEYE_WAITING);
	bigEyeActivity = BIGEYE_WAITING;
	healthPoint = BIGEYE_HEALTH_POINTS;
	attackDamage = BIGEYE_ATTACK_DAMAGE;
	points = BIGEYE_POINTS;
}


BigEye::~BigEye()
{
}

void BigEye::update()
{
	bigEyeDelay.update();

	if (ground)
	{
		bigEyeDelay.start();
		bigEyeActivity = BIGEYE_WAITING;
		initDirectionFollowRockman();
		int number = randomFrom(-2, 1);// TODO: luu constant
		if (number < 0)
			initJumpHigh();
		else
			initJumpFar();
	}

	switch (bigEyeActivity)
	{
	case BIGEYE_WAITING:
		setAction(BIGEYE_WAITING);
		setHeight(BIGEYE_WAITING_WIDTH);
		dx = 0;
		if (bigEyeDelay.isTerminated())
		{
			bigEyeActivity = BIGEYE_FLYING;
		}
		break;
	case BIGEYE_FLYING:
		setAction(BIGEYE_FLYING);
		setHeight(BIGEYE_FLYING_WIDTH);
		Enemy::update();

		break;
	default:
		break;
	}

	ground = false;

}


