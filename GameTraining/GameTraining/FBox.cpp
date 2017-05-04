#include "FBox.h"
#include"Collision.h"
#include<iostream>
using namespace std;

extern double collisionTime; 
extern float nx, ny;

int time = BOX_TIME;

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
		slideHandle();
		//slideHandle();
	}
}

void FBox::onIntersect(FBox * other)
{
}

void FBox::slideHandle()
{
	//float remainingTime = 1.0f - collisionTime;

	//float dotprod = (dx*ny + dy*nx) * remainingTime;
	//dx = dotprod*ny;
	//dy = dotprod*nx;

	if (nx != 0)
	{
		isChangeDelta = true;
		dx = dx*collisionTime;
		return;
	}
	if (ny != 0)
	{
		isChangeDelta = true;
		dy = dy*collisionTime;
		return;
	}
}

FBox::FBox()
{
	alive = true;
	collisionType = CT_GROUND;
	dx = 0;
	dy = 0;
	vx = 0;
	vy = 0;
	ax = 0;
	ay = BOX_GRAVITATIONAL_ACCELERATION; // Gravitational acceleration gia toc trong truong 
}


FBox::~FBox()
{
}


