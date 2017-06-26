#pragma once
#include "Enemy.h"

enum GMR_ACTIVITY {
	GMR_FALLING,
	GMR_THROWING
};

enum GMR_THROW_ACTIVITY {
	GMR_THROW_NORMAL,
	GMR_THROW_BREAKING
};

class GutsmanRock :
	public Enemy
{
public:
	static GutsmanRock* instance;
	static GutsmanRock* getInstance();

	GMR_ACTIVITY gmrActivity;

	GMR_THROW_ACTIVITY gmrThrowActivity;

	void update();
	void render();
	GutsmanRock();
	~GutsmanRock();
};

