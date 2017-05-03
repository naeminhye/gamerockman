#pragma once
#include "Enemy.h"
enum OCTOPUS_TYPE
{
	OCTOPUS_HORIZONTAL = 105,
	OCTOPUS_VERTICAL = 5
};
enum OCTOPUS_ACTION	
{
	OCTOPUS_CLOSE_EYES,
	OCTOPUS_OPEN_EYES
};
enum OCTOPUS_ACTIVITY
{
	OCTOPUS_WAITING,
	OCTOPUS_RUNNING
};
class OctopusBattery :
	public Enemy

{
public:
	OCTOPUS_ACTIVITY octopusActivity;
	DelayTime octopusDelay;
	void updateLocation();
	void update();
	void onCollision(FBox* other, int nx, int ny);
	void init();

	OctopusBattery();
	~OctopusBattery();
};

