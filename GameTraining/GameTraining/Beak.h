#pragma once
#include "Enemy.h"
#include "BeakBullet.h"

/* ENUMERATIONS */
enum BEAK_TYPE {
	// Beak co 2 loai, 1 loai huong ve phia trai (BEAK_LEFT), 1 loai huong ve phia ben phai (BEAK_RIGHT)
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
	// cac hanh dong Sprite cua Beak
	BEAK_WAITING,
	BEAK_OPENING,
	BEAK_SHOOTING,
	BEAK_CLOSING
};

enum BULLET_LOCATION_ACTIVITY
{
	// vi tri dan cua Beak khi ban ra
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

	bool setHealthPoint(int healthPoint);
	void updateLocation();
	void update();
	bool updateAttack();
	void onLastFrameAnimation(); 
	void init();
	
	/* CONSTRUCTOR & DESTRUCTOR */
	Beak();
	~Beak();

};

