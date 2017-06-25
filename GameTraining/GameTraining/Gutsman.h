#pragma once
#include "Enemy.h"

enum GUTSMAN_ACTION {
	GM_WAITING,
	GM_JUMPING,
	GM_HOLDING_ROCK, 
	GM_THROWING_ROCK,
	GM_EXPLOSE
};

enum GM_DECISION {
	GM_D_WAIT,
	GM_D_ATTACK
};

enum GM_ACTIVITY {
	GMA_GROUND,
	GMA_JUMP
};

enum GM_ATTACK_ACTIVITY {

};

class Gutsman :
	public Enemy
{
public:

	int* gmDecisionTable;
	bool gmCanSelect;
	int gmRandCount;

	GM_DECISION decision;

	DelayTime gm_waiting_delay;

	void update();

	void gmSelectAttack();

	Gutsman();
	~Gutsman();
};

