#include "Flea.h"



Flea::Flea()
{
}


Flea::~Flea()
{
}

void Flea::update()
{
	if (ground)
		vy = 0.4;
	Enemy::update();

}

