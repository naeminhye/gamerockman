#pragma once
#include "MovableObject.h"

enum SCISSORS_ACTIVITY {
	SCISSORS_KOBIET, // TODO SUA SAU
	SCISSORS_RETURN
};

class CutmanScissors :
	public MovableObject
{
public:
	BaseObject* cutman;
	static CutmanScissors* instance;
	static CutmanScissors* getInstance();
	SCISSORS_ACTIVITY scissorsActivity;
	void update();
	CutmanScissors();
	~CutmanScissors();
};

