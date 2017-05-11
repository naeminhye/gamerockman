#pragma once
#include "Map.h"
class CutmanMap :
	public Map
{
public:
	Stage* findNextStageOnDoor();
	void render();
	void update();
	CutmanMap();
	~CutmanMap();
};

