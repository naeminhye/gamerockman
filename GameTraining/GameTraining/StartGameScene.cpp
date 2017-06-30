#include "StartGameScene.h"
#include"CutmanMap.h"
#include"GutsmanMap.h"
#include "TextSprite.h"
#include "NumberSprite.h"

extern int randomFrom(int numBegin, int numEnd);

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

	if (delay.atTime())
	{
		boss->update(0, frameIndex);

	}

	if (startGameDelay.isTerminated())
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
	D3DXMATRIX flipMatrix;

	int middleX, middleY;
	middleX = BACKBUFFER_WIDTH / 2;
	middleY = BACKBUFFER_HEIGHT / 2;

	RECT r;
	SetRect(&r, 0, 0, BACKBUFFER_WIDTH, BACKBUFFER_HEIGHT);
	img->RenderTexture(0, 0, &r);

	if (startGameDelay.isOnTime())
	{
		boss->render(middleX - 50, middleY - 15, 0, frameIndex);
		if (curSelect == MT_CUTMAN)
		{
			TextSprite::getInstance()->render(middleX + 10, middleY - 15, "CUTMAN"); // TODO

		}
		else {
			TextSprite::getInstance()->render(middleX + 10, middleY - 15, "GUTSMAN");
		}
		TextSprite::getInstance()->render(middleX + 10, middleY, "CLEAR"); // TODO
		TextSprite::getInstance()->render(middleX + 60, middleY, "POINT"); // TODO

		NumberSprite::getInstance()->render(middleX + 10, middleY + 15, 6, Rockman::getInstance()->clearPoint);
	}


}

StartGameScene::StartGameScene()
{
	img = new Texture();
	curSelect = SelectMapScene::instance->curSelect;
	startGameDelay.init(START_GAME_DELAY_TIME);
	startGameDelay.start();
	GameSound::getInstance()->play(SOUND_GAME_START);

	//boss = new Sprite();
	if (curSelect == MT_CUTMAN)
		boss = SpriteManager::getInstance()->sprites[SPR_CUTMAN];
	else {
		boss = SpriteManager::getInstance()->sprites[SPR_GUTSMAN];
	}

	board.x = 50;
	board.y = 50;

	frameIndex = 0;
	delay.tickPerFrame = BASE_OBJECT_TICK_PER_FRAME;

	Rockman::getInstance()->clearPoint = randomFrom(5, 10) * 10000;

}


StartGameScene::~StartGameScene()
{
}
