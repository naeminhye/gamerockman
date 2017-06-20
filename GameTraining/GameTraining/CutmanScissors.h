#pragma once
#include "MovableObject.h"

/* ENUMERATIONS */
enum SCISSORS_ACTIVITY {
	SCISSORS_ATTACK, // trang thai hoat dong luc keo cua Cutman duoc phong ve phia Rockman
	SCISSORS_RETURN // trang thai hoat dong luc keo cua Cutman quay ve
};

class CutmanScissors :
	public MovableObject
{
public:
	BaseObject* cutman;
	static CutmanScissors* instance;
	SCISSORS_ACTIVITY scissorsActivity;

	static CutmanScissors* getInstance();
	void update();

	/* CONSTRUCTOR & DESTRUCTOR */
	CutmanScissors();
	~CutmanScissors();

};

