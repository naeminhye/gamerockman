#pragma once
#include "RockmanBullet.h"

enum RM_BULLET_CUT_ACTIVITY {
	RBC_GO,
	RBC_RETURN
};

class RockmanCutBullet :
	public RockmanBullet
{
public:
	RM_BULLET_CUT_ACTIVITY rbcActivity;
	void update();
	RockmanCutBullet();
	~RockmanCutBullet();
};

