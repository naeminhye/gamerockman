#pragma once
#include "Enemy.h"
#include "BeakBullet.h"

enum BEAK_TYPE {

};

enum BEAK_ACTION 
{
	BEAK_CLOSED,
	BEAK_OPENING,  
	BEAK_SHOOTING,
	BEAK_CLOSING
};

class Beak :
	public Enemy
{
public:
	BEAK_ACTION beakAction;
	MGMGameTime delay;
	
	void updateBeakSprite();
	DelayTime beakDelay;

	void update();
	void updateAttack();
	Beak();
	~Beak();
};

