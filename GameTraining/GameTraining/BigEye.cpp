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
	bigEyeDelay.init(BIGEYE_DELAYTIME); // TODO luu constant
	bigEyeDelay.start();
	setAction(BIGEYE_WAITING);
	bigEyeActivity = BIGEYE_WAITING;

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
		//vy = 0.4; // TODO: luu constant
		int number = randomFrom(-2, 1);
		if (number < 0)
			initJumpHigh();
		else
			initJumpFar();
	}

	switch (bigEyeActivity)
	{
	case BIGEYE_WAITING:
		setAction(BIGEYE_WAITING);
		setHeight(40); // TODO luu constant 
		dx = 0;
		if (bigEyeDelay.isTerminated())
		{
			bigEyeActivity = BIGEYE_FLYING;
		}
		break;
	case BIGEYE_FLYING:
		setAction(BIGEYE_FLYING);
		setHeight(48); // TODO luu constant 
		Enemy::update();

		break;
	default:
		break;
	}

	ground = false;

}


