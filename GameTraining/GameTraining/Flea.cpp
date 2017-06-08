#include "Flea.h"



void Flea::initJumpHigh()
{
	vy = FLEA_JUMP_HIGH_VY;
	vx = direction * FLEA_JUMP_HIGH_VX;
}

void Flea::initJumpFar()
{
	vy = FLEA_JUMP_FAR_VY;
	vx = direction * FLEA_JUMP_FAR_VX;
}

Flea::Flea()
{
	fleaDelay.init(FLEA_DELAYTIME); 
	fleaDelay.start();
	setAction(FLEA_WAITING);
	fleaActivity = FLEA_WAITING;
	healthPoint = 1;
	attackDamage = 2;
}


Flea::~Flea()
{
}

void Flea::update()
{
	fleaDelay.update();

	if (ground)
	{
		fleaDelay.start();
		fleaActivity = FLEA_WAITING;
		initDirectionFollowRockman();
		//vy = 0.4; // TODO: luu constant
		int number = randomFrom(-2, 1);
		if (number < 0)
			initJumpHigh();
		else
			initJumpFar();
	}

	switch (fleaActivity)
	{
	case FLEA_WAITING:
		setAction(FLEA_WAITING);
		setHeight(FLEA_WAITING_WIDTH);
		dx = 0;
		if (fleaDelay.isTerminated())
		{
			fleaActivity = FLEA_FLYING;
		}
		break;
	case FLEA_FLYING:
		setHeight(FLEA_FLYING_WIDTH); 
		setAction(FLEA_FLYING);
		Enemy::update();
		
		break;
	default:
		break;
	}

	ground = false;

}


