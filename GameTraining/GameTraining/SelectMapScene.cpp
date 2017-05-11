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
	bool keyEnterPress = KEY::getInstance()->isEnterPress;
	bool keySpacePress = KEY::getInstance()->isJumpPress;
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
	}
}

void SelectMapScene::render()
{
	RECT r;
	SetRect(&r, 0, 0, 256, 216);
	img->RenderTexture(0, 0, &r);
	//TextSprite::getInstance()->render(10, 10, "START");
	
}

SelectMapScene::SelectMapScene()
{
	img = new MGMTexture();

}


SelectMapScene::~SelectMapScene()
{
}
