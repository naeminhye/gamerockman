#pragma once
#include "Map.h"
class CutmanMap :
	public Map
{
public:
	Stage* findNextStageOnDoor();
	CutmanMap();
	~CutmanMap();
};

