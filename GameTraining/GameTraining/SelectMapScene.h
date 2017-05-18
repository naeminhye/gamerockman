#pragma once
#include "Scene.h"
#include "MGMTexture.h"
#include "SelectMapFrame.h"

enum MAP_TYPE {
	MT_CUTMAN,
	MT_GUTSMAN,

	MT_COUNT
};

class SelectMapScene :
	public Scene
{
public:
	MGMTexture* img;
	SelectMapFrame* selectMapFrames;
	MAP_TYPE curSelect;
	void init();
	void update();
	void render();
	SelectMapScene();
	~SelectMapScene();
};

