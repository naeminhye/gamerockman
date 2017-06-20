#pragma once
#include "Enemy.h"
enum FLY_ACTIVITY
{
	FLY_RUNNING,
	FLY_STANDING
};
enum FLY_ACTION
{
	FLY_CLOSE,
	FLY_OPEN
};
class FlyingShell :
	public Enemy
{
public:
	FLY_ACTIVITY flyactivity;
	DelayTime flydelay;
	void update();
	void onCollision(FBox* other, int nx, int ny);

	/* CONSTRUCTOR & DESTRUCTOR */
	FlyingShell();
	~FlyingShell();

};

