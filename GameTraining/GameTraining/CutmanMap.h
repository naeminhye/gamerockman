#pragma once
#include "Map.h"
class CutmanMap :
	public Map
{
public:
	Stage* findNextStageOnDoor(); // tim dia chi cua Stage ke tiep sau khi Rockman di qua cua
	void render();
	void update();

	/* CONSTRUCTOR & DESTRUCTOR */
	CutmanMap();
	~CutmanMap();

};

