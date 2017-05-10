#pragma once
#include "Scene.h"
#include "MGMTexture.h"
class SelectMapScene :
	public Scene
{
public:
	MGMTexture* img;
	void init();
	void update();
	void render();
	SelectMapScene();
	~SelectMapScene();
};

