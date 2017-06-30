#include "Trundle.h"
#include "Rockman.h"

extern float roundToInt(float num);

void Trundle::update()
{
	MovableObject::update();
	dy = 0;
}

void Trundle::updateMove()
{
	MovableObject::updateMove();
	/*vx += ax*BOX_TIME;
	dx = roundToInt(vx*BOX_TIME);*/
}

void Trundle::onIntersect(FBox * other)
{
	if (other->collisionType == CT_BRIDGE)
	{
		BaseObject* otherObj = (BaseObject*)other;

		if (otherObj->id == BRIDGE_DASH)
		{
			if (left() + 8 + dx > other->right() && vx > 0 || (left() + dx < other->left() && vx < 0))// TODO
				setAction(TRUNDLE_NORMAL);
			else
				setAction(TRUNDLE_THROW);
			return;
		}

		if(otherObj->id == BRIDGE_LEFT)
		{
			setAction(TRUNDLE_NORMAL);
			if ((left() + dx < other->left() && vx < 0)) // TODO them constant
				//vx = -roundToInt(vx);
				vx = -vx;
		}
		else if (otherObj->id == BRIDGE_RIGHT)
		{
			setAction(TRUNDLE_NORMAL);
			if ((left() + 8 + dx > other->right() && vx > 0))// TODO
				//vx = -roundToInt(vx);
				vx = -vx;

		}
		
		
	}
}

void Trundle::onCollision(FBox * other, int nx, int ny)
{
	if (other == Rockman::getInstance())
	{
		if (ny == 1)
		{
			Rockman::getInstance()->dx += this->dx;
		}

		if (action == TRUNDLE_NORMAL)
		{
			collisionType = CT_GROUND;
			Rockman::getInstance()->onCollision(this, nx, ny);
			collisionType = CT_TRUNDLE;
		}
	}
}

void Trundle::onLastFrameAnimation()
{
	if (action == TRUNDLE_THROW)
		pauseAnimation = true;
	else
		pauseAnimation = false;

}

Trundle::Trundle()
{
	vx = -0.1;// TODO
	collisionType = CT_TRUNDLE;
	direction = Left;
	action = TRUNDLE_NORMAL;
	vy = 0;// TODO
	pauseAnimation = false;
}


Trundle::~Trundle()
{
}
