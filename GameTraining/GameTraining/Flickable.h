#pragma once
#include "MovableObject.h"
#include "DelayTime.h"
#include"Enemy.h"

class Flickable :
	public Enemy
{
public:
	int flickerAction;// TODO set gia tri *****
	DelayTime injuryDelay, flickeringDelay;
	MGMGameTime disappearTime;
	bool isDisappear;
	void updateFlicker(); // khi trung dan
	virtual void render();
	Flickable();
	~Flickable();
};

