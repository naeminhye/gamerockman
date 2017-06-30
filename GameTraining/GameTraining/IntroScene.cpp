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
		GameSound::getInstance()->play(SOUND_GAME_START);
		Scene::changeScene(new SelectMapScene());
	}

}

void IntroScene::render()
{
	RECT r;
	SetRect(&r, 0, 0, BACKBUFFER_WIDTH, BACKBUFFER_HEIGHT);
	img->RenderTexture(0, 0, &r);
}

IntroScene::IntroScene()
{
	img = new Texture();

}


IntroScene::~IntroScene()
{
}
