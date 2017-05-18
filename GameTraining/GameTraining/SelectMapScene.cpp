#include "SelectMapScene.h"
#include "KEY.h"
#include"MapScene.h"
#include"CutmanMap.h"
#include"GutsmanMap.h"
#include "TextSprite.h"

void SelectMapScene::init()
{
	img->Init("Data\\Sprite\\Scene\\stageselect.png", D3DCOLOR_XRGB(0, 0, 0));

}

void SelectMapScene::update()
{
	/*
	if (keyEnterPress)
	{
		MapScene* mapScene = new MapScene();
		Scene::changeScene(mapScene);
		mapScene->setCurMap(new CutmanMap());

	}
	else if (keySpacePress)
	{
		MapScene* mapScene = new MapScene();
		Scene::changeScene(mapScene);
		mapScene->setCurMap(new GutsmanMap());
	}*/

	bool keyLeft = KEY::getInstance()->isLeftPress;
	bool keyRight = KEY::getInstance()->isRightPress; 
	bool keyEnterPress = KEY::getInstance()->isEnterPress;

	if (keyRight)
	{
		curSelect = (MAP_TYPE)((curSelect + 1) % MT_COUNT);
	}
	else if (keyLeft)
	{
		if (curSelect == 0)
		{
			curSelect = MT_COUNT;
		}
		curSelect = (MAP_TYPE)(curSelect-1);
	}

	selectMapFrames[curSelect].update();

	if (keyEnterPress)
	{
		MapScene* mapScene = new MapScene();
		Rockman::getInstance()->rm_type = RMT_NORMAL;
		Rockman::getInstance()->pauseAnimation = true;
		Rockman::getInstance()->ground = false;
		Rockman::getInstance()->setAction(RM_TELEPORT);
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

void SelectMapScene::render()
{
	RECT r;
	SetRect(&r, 0, 0, 256, 216);
	img->RenderTexture(0, 0, &r);

	selectMapFrames[curSelect].render();
	
	//TextSprite::getInstance()->render(10, 10, "START");

	
}

SelectMapScene::SelectMapScene()
{
	img = new MGMTexture();
	selectMapFrames = new SelectMapFrame[MT_COUNT];
	selectMapFrames[MT_CUTMAN].x = 74;
	selectMapFrames[MT_CUTMAN].y = 17;
	selectMapFrames[MT_GUTSMAN].x = 138;
	selectMapFrames[MT_GUTSMAN].y = 17;
	curSelect = MT_CUTMAN;
}


SelectMapScene::~SelectMapScene()
{
}
