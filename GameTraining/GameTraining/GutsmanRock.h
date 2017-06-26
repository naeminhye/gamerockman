#pragma once
#include "Enemy.h"

enum GMR_ACTIVITY {
	GMR_FALLING,
	GMR_THROWING
};

enum GMR_THROW_ACTIVITY {
	GMR_THROW_NORMAL,
	GMR_THROW_BREAKING,
	GMR_THROW_FINISH
};

class GutsmanRock :
	public Enemy
{
public:
	static GutsmanRock* instance;
	static GutsmanRock* getInstance();

	GMR_ACTIVITY gmrActivity;

	GMR_THROW_ACTIVITY gmrThrowActivity;

	DelayTime rockBreakingDelay;

	bool onBreaking;

	void update();
	void render();
	void updateRockBreaking();

	void onCollision(FBox* other, int nx, int ny);

	GutsmanRock();
	~GutsmanRock();
};

