#pragma once
#include "Enemy.h"

/* ENUMERATIONS */
enum MET_ACTIVITY
{
	MET_WAITING,
	MET_SHOOTING
};

enum MET_ACTION
{
	MET_CLOSE,
	MET_OPEN 
};

class Met :
	public Enemy
{
	
public:
	MET_ACTIVITY metActivity;
	DelayTime metDelay;

	bool setHealthPoint(int healthPoint);
	void update();
	void init();

	/* CONSTRUCTOR & DESTRUCTOR */
	Met();
	~Met();

};

