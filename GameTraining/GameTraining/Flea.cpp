#include "Flea.h"



Flea::Flea()
{
	fleaDelay.init(500);
	fleaDelay.start();
	setAction(FLEA_WAITING);
	fleaActivity = FLEA_WAITING;

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
		vy = 0.4;
	}

	switch (fleaActivity)
	{
	case FLEA_WAITING:
		setAction(FLEA_WAITING);
		setHeight(15);
		if (fleaDelay.isTerminated())
		{
			fleaActivity = FLEA_FLYING;

		}
		break;
	case FLEA_FLYING:
		setHeight(19);
		setAction(FLEA_FLYING);
		Enemy::update();
		break;
	default:
		break;
	}

	ground = false;

}

void Flea::onLastFrameAnimation()
{
}

