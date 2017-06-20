#pragma once
#include "Enemy.h"
#include "Rockman.h"

/* ENUMERATIONS */
enum BLADER_ACTIVITY {
	BLADER_PREPARE,
	BLADER_ATTACK
};

class Blader :
	public Enemy
{
public:
	int xTarget, yTarget; // toa do x, y cua Rockman ma Blader bay theo de tan cong
	BLADER_ACTIVITY bladerActivity;

	void update();
	void onCollision(FBox* other, int nx, int ny);

	/* CONSTRUCTOR & DESTRUCTOR */
	Blader();
	~Blader();

};

