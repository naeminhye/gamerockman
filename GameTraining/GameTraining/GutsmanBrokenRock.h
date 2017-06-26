#pragma once
#include "Enemy.h"
class GutsmanBrokenRock :
	public Enemy
{
public:

	static List<GutsmanBrokenRock*>* rocks;

	void update();
	void render();
	void deleteRock();
	void updateLocation();
	void onCollision(FBox* other, int nx, int ny);

	GutsmanBrokenRock();
	~GutsmanBrokenRock();
};

