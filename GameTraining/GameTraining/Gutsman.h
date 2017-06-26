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
	GM_ATTACK_RAISING_HAND,
	GM_ATTACK_ROCK_FALLING,
	GM_ATTACK_HOLDING_ROCK,
	GM_ATTACK_THROWING_ROCK,
	GM_ATTACK_FINISH // TODO them hanh dong
};

class Gutsman :
	public Enemy
{
public:

	static Gutsman* instance;

	int* gmDecisionTable;
	bool gmCanSelect;
	int gmRandCount;

	GM_DECISION decision;
	GM_ACTIVITY gmActivity;
	GM_ATTACK_ACTIVITY gmAttackActivity;

	DelayTime gm_waiting_delay;
	DelayTime gm_attacking_delay;

	void update();
	void updateAttack(); 
	void onLastFrameAnimation();

	void onCollision(FBox* other, int nx, int ny);

	void gmSelectAttack();


	void updateLocation();

	Gutsman();
	~Gutsman();
};

