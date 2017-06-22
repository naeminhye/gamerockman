#pragma once
#include "MovableObject.h"
#include "DelayTime.h"
#include"Enemy.h"

class Flickable :
	public Enemy
{
public:
	int flickerAction;// TODO set gia tri *****
	int injuryAction;// TODO set gia tri *****
	DelayTime injuryDelay, flickeringDelay;
	GameTime disappearTime;
	bool isDisappear;
	void updateFlicker(); // khi trung dan
	virtual void render();

	/* CONSTRUCTOR & DESTRUCTOR */
	Flickable();
	~Flickable();
};

