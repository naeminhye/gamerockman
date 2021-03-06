#pragma once
#include "Scene.h"
#include "Texture.h"
#include "DelayTime.h"
#include "SelectMapScene.h"
#include "SelectRockmanBoard.h"
#include"MapScene.h"
#include "Sprite.h"

class StartGameScene :
	public Scene
{
public:
	Texture* img;
	MAP_TYPE curSelect;
	Sprite* boss;
	int frameIndex;
	GameTime delay;

	SelectRockmanBoard board;
	DelayTime startGameDelay;

	void init();
	void update();
	void render();

	StartGameScene();
	~StartGameScene();
};

