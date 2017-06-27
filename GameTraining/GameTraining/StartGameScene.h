#pragma once
#include "Scene.h"
#include "MGMTexture.h"
#include "DelayTime.h"
#include "SelectMapScene.h"

class StartGameScene :
	public Scene
{
public:
	MGMTexture* img;
	MAP_TYPE curSelect;

	DelayTime startGameDelay;

	void init();
	void update();
	void render();

	StartGameScene();
	~StartGameScene();
};

