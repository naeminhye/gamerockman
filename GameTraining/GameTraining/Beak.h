#pragma once
#include "Enemy.h"
#include "BeakBullet.h"

enum BEAK_TYPE {
	BEAK_LEFT = 2, // co direction = left
	BEAK_RIGHT = 102
};

enum BEAK_ACTION 
{
	BEAK_OPEN,
	BEAK_CLOSE
};

enum BEAK_ACTIVITY
{
	BEAK_WAITING,
	BEAK_OPENING,
	BEAK_SHOOTING,
	BEAK_CLOSING
};

enum BULLET_LOCATION_ACTIVITY
{
	TOP,
	MIDDLE_TOP,
	MIDDLE_BOTTOM,
	BOTTOM
};

class Beak :
	public Enemy
{
public:
	BEAK_ACTIVITY beakActivity;
	BULLET_LOCATION_ACTIVITY bulletLocation;
	DelayTime bulletDelay;
	
	DelayTime beakDelay;
	void updateLocation();
	void update();
	bool updateAttack();
	void onLastFrameAnimation();
	void init();
	
	Beak();
	~Beak();
};

