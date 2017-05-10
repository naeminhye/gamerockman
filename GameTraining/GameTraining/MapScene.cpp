#include "MapScene.h"

MapScene::MapScene(void)
{

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
}

void MapScene::update()
{
	curMap->update();

}
void MapScene::render()
{

	curMap->render();
	Rockman::getInstance()->render();
}


MapScene::~MapScene(void)
{
}
