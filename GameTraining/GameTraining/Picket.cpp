#include "Picket.h"



Picket::Picket()
{
	vx = -0.1; //***
}


Picket::~Picket()
{
}

void Picket::update()
{
	Enemy::update();
	if (Rockman::getInstance()->xCenter() > xCenter())
		direction = Right;
	else
		direction=Left;
	vx = direction * 0.1;
}
