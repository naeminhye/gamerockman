#pragma once
#include "Map.h"
class GutsmanMap :
	public Map
{
public:
	Stage* findNextStageOnDoor();

	/* CONSTRUCTOR & DESTRUCTOR */
	GutsmanMap();
	~GutsmanMap();

};

