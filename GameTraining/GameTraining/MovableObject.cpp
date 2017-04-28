#include "MovableObject.h"



void MovableObject::update()
{
	ground = false;
	BaseObject::update();
	FBox::updateMove();
}

void MovableObject::onCollision(FBox * other, int nx, int ny)
{
	if (other->collisionType == CT_GROUND && ny == 1)
		ground = true;
	BaseObject::onCollision(other, nx, ny);
}

void MovableObject::setWidth(int width)
{
	this->width = width;
}

void MovableObject::setHeight(int height)
{
	this->height = height;
}

MovableObject::MovableObject()
{
	//dx = -1;
	dy = 0;
}


MovableObject::~MovableObject()
{
}
