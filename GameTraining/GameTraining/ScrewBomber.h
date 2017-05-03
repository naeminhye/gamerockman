#pragma once
#include "Enemy.h"
enum SCREW_TYPE
{
	SCREW_TOP = 110,
	SCREW_BOTTOM = 10
};
enum SCREW_ACTIVITY
{
	SCREW_SHOOTING,
	SCREW_WAITING
};
enum SCREW_ACTION
{
	SCREW_SHOOT,
	SCREW_WAIT
};
class ScrewBomber :
	public Enemy
{
public:
	SCREW_ACTIVITY screwactivity;
	DelayTime screwdelay;
	void updateLocation();
	void update();
	void render();
	void setHeight(int height);
	ScrewBomber();
	~ScrewBomber();
};

