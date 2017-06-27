#include "StartGameScene.h"
#include"MapScene.h"
#include"CutmanMap.h"
#include"GutsmanMap.h"
#include "TextSprite.h"


void StartGameScene::init()
{
	img->Init("Data\\Sprite\\Scene\\startgame.png", D3DCOLOR_XRGB(0, 0, 0));
	GameSound::getInstance()->stop(SOUND_STAGE_SELECT);
}

void StartGameScene::update()
{
	startGameDelay.update();

	MapScene* mapScene = new MapScene();
	Rockman::getInstance()->rm_type = RMT_NORMAL;
	Rockman::getInstance()->pauseAnimation = true;
	Rockman::getInstance()->ground = false;
	Rockman::getInstance()->setAction(RM_TELEPORT);



	if(startGameDelay.isTerminated())
	{
		switch (curSelect)
		{
		case MT_CUTMAN:
			Scene::changeScene(mapScene);
			mapScene->setCurMap(new CutmanMap());
			break;
		case MT_GUTSMAN:
			Scene::changeScene(mapScene);
			mapScene->setCurMap(new GutsmanMap());
			break;
		default:
			break;
		}
	}
}

void StartGameScene::render()
{
	RECT r;
	SetRect(&r, 0, 0, BACKBUFFER_WIDTH, BACKBUFFER_HEIGHT);
	img->RenderTexture(0, 0, &r);

	int middleX, middleY;
	middleX = BACKBUFFER_WIDTH / 2;
	middleY = BACKBUFFER_HEIGHT / 2;

	if (startGameDelay.isOnTime())
	{
		if(curSelect == MT_CUTMAN)
		TextSprite::getInstance()->render(middleX + 10, middleY - 15, "CUTMAN");
		else {
			TextSprite::getInstance()->render(middleX + 10, middleY - 15, "GUTSMAN");
		}
		//board.render();
	}


}

StartGameScene::StartGameScene()
{
	img = new MGMTexture();
	curSelect = SelectMapScene::instance->curSelect;
	startGameDelay.init(5000);
	startGameDelay.start();
	GameSound::getInstance()->play(SOUND_GAME_START);

	board.x = 50;
	board.y = 50;
}


StartGameScene::~StartGameScene()
{
}
