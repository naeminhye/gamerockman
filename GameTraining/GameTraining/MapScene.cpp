#include "MapScene.h"
#include "HealthSprite.h"
#include "NumberSprite.h"
#include "KEY.h"

MapScene::MapScene(void)
{
	selection = 1;
}
MapScene* MapScene::instance=0;

MapScene* MapScene::getInstance()
{
	if(instance==0)
		instance = new MapScene();
	return instance;
}

void MapScene::setCurMap(Map * map)
{
	if (curMap != 0)
	{
		delete curMap;
	}
	curMap = map;
}

void MapScene::readFile(const char * objectsPath)
{
	int t;
	ifstream fs(objectsPath);
	fs >> nObject;
	objects = new BaseObject[nObject];
	for (auto i = 0; i < nObject; i++)
	{
		fs >> t;
		fs >> objects[i].x
			>> objects[i].y
			>> objects[i].width
			>> objects[i].height;
		objects[i].y = curMap->rowCount * 16 - objects[i].y;
	}
}

void MapScene::init()
{
	curMap = 0;

	// TODO
	board.x = 130;
	board.y = 38; 
}

void MapScene::update()
{
	bool keyUp = KEY::getInstance()->isUpPress;
	bool keyDown = KEY::getInstance()->isDownPress;
	bool keyEnterPress = KEY::getInstance()->isEnterPress;
	curMap->update();
	if (Map::curMap->isChangingType)
	{
		if (keyDown)
		{
			selection = (selection + 1) % 2;
		}
		else if (keyUp)
		{
			selection = (selection - 1) % 2;
		}

	}
	else 
	{
		if (selection < 0)
		{
			selection = -selection;
		}
		switch (selection)
		{
		case 1:
			Rockman::getInstance()->rm_type = ROCKMAN_TYPE::RMT_NORMAL;
			Rockman::getInstance()->action = Rockman::getInstance()->rm_type* RM_ACTION_COUNT + Rockman::getInstance()->rm_action;
			break;
		case 0:
			Rockman::getInstance()->rm_type = ROCKMAN_TYPE::RMT_GUSTMAN;
			Rockman::getInstance()->action = Rockman::getInstance()->rm_type* RM_ACTION_COUNT + Rockman::getInstance()->rm_action;
			break;
		default:
			break;
		}
	
	}
}
void MapScene::render()
{

	curMap->render();
	Rockman::getInstance()->render();
	HealthSprite::getInstance()->render(10, 80, Rockman::getInstance()->health, Rockman::getInstance()->maxHealth); // TODO

	if (Map::curMap->isChangingType)
	{
		board.render();
		SpriteManager::getInstance()->sprites[SPR_ITEMS]->render(172, 162, 0, 25); // TODO
		NumberSprite::getInstance()->render(196, 167, 2, Rockman::getInstance()->life);
	}
}


MapScene::~MapScene(void)
{
}
