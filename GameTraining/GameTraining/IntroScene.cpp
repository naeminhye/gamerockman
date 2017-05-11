#include "IntroScene.h"
#include "MapScene.h"
#include "SelectMapScene.h"
#include "KEY.h"


void IntroScene::init()
{
	img->Init("Data\\Sprite\\Scene\\introscene.png", D3DCOLOR_XRGB(0, 0, 0));

}

void IntroScene::update()
{
	bool keyEnterPress = KEY::getInstance()->isEnterPress;
	if (keyEnterPress)
	{
		Scene::changeScene(new SelectMapScene());
	}

}

void IntroScene::render()
{
	RECT r;
	SetRect(&r, 0, 0, 256, 216);
	img->RenderTexture(0, 0, &r);
}

IntroScene::IntroScene()
{
	img = new MGMTexture();

}


IntroScene::~IntroScene()
{
}
