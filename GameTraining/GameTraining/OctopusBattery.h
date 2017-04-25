#pragma once
#include "Enemy.h"
enum OCTOPUS_ACTIVITY
{
	OCTOPUS_WAITING,
	OCTOPUS_RUNNING
};
class OctopusBattery :
	public Enemy

{
public:
	virtual void update();
	OctopusBattery();
	~OctopusBattery();
};

