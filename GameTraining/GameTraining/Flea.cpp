#include "Flea.h"



Flea::Flea()
{
	setAction(FLEA_WAITING);
}


Flea::~Flea()
{
}

void Flea::update()
{
	if (ground)
	{
		vy = 0.4;

	}
	else {
		


	}
	Enemy::update();

}

void Flea::onLastFrameAnimation()
{
}

