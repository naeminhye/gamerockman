#include "FBox.h"
#include"Collision.h"
#include<iostream>
using namespace std;

int time = 15; //

void FBox::updateLocation()
{
	if (isCollision && !isChangeDelta)
	{
		if (abs(dx) > abs(dy))
			dy = 0;
		else
			dx = 0;
	}
	x += dx;
	y += dy;
}

void FBox::update()
{
	isChangeDelta = false;
	isCollision = false;
}

void FBox::updateMove()
{
	vx += ax*time;
	vy += ay*time;
	dx = vx*time;
	dy = vy*time;
}

void FBox::onCollision(FBox * other, int nx, int ny)
{
	if (other->collisionType == CT_GROUND)
	{
		//van toc khong duoc tang dan deu khi dung tren san
		if (ny != 0)
			vy = -0.1f; //****
		Collision::PreventMoving(this, other);
	}
}

void FBox::onIntersect(FBox * other)
{
}

FBox::FBox()
{
	collisionType = CT_GROUND;
	dx = 0;
	dy = 0;
	vx = 0;
	vy = 0;
	ax = 0;
	ay = -0.001; // Gravitational acceleration gia toc trong truong 
}


FBox::~FBox()
{
}
