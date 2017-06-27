#include "StartGameScene.h"
#include"MapScene.h"
#include"CutmanMap.h"
#include"GutsmanMap.h"


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

}

StartGameScene::StartGameScene()
{
	img = new MGMTexture();
	curSelect = SelectMapScene::instance->curSelect;
	startGameDelay.init(5000);
	startGameDelay.start();
}


StartGameScene::~StartGameScene()
{
}
