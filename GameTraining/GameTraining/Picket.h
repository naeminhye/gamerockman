#pragma once
#include "Enemy.h"
enum PICKET_ACTIVITY
{
	PICKET_WAITING,
	PICKET_SHOOTING
};
enum PICKET_ACTION
{
	PICKET_WAIT,
	PICKET_SHOOT
};
class Picket :  public Enemy
{
public:
	PICKET_ACTIVITY picketActivity;
	DelayTime picketDelay;
	DelayTime picketbulletDelay;
	Picket();
	~Picket();
	void update();
};

