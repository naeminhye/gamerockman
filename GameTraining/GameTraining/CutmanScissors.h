#pragma once
#include "Enemy.h"

/* ENUMERATIONS */
enum SCISSORS_ACTIVITY {
	SCISSORS_ATTACK, // trang thai hoat dong luc keo cua Cutman duoc phong ve phia Rockman
	SCISSORS_RETURN // trang thai hoat dong luc keo cua Cutman quay ve
};

class CutmanScissors :
	public Enemy
{
public:
	BaseObject* cutman;
	static CutmanScissors* instance;
	SCISSORS_ACTIVITY scissorsActivity;
	void slideHandle();
	void updateLocation();

	static CutmanScissors* getInstance();
	void update();
	void onCollision(FBox* other, int nx, int ny);

	void setDy(int dy);

	/* CONSTRUCTOR & DESTRUCTOR */
	CutmanScissors();
	~CutmanScissors();

};

