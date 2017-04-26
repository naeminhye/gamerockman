#include "MGMGame.h"


MGMGame::MGMGame(void)
{
}
MGMGame* MGMGame::instance=0;

MGMGame* MGMGame::getInstance()
{
	if(instance==0)
		instance = new MGMGame();
	return instance;
}

void MGMGame::readFile(const char * objectsPath)
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
		objects[i].y = tilemap.rowCount * 16 - objects[i].y;
	}
}

void MGMGame::init()
{
	camera = MGMCamera::getInstance();
	Rockman::getInstance()->x = 95;
	Rockman::getInstance()->y = 91;
	Rockman::getInstance()->width = 22;
	Rockman::getInstance()->height = 22;
	Rockman::getInstance()->action = 2;
	/*brick.x = 200;
	brick.y = 200;
	brick.width = 16;
	brick.height = 22;
	brick.action = 0;*/
	tilemap.init("Data\\Map\\Cutman\\tileSheet.png", "Data\\Map\\Cutman\\matrix.txt",
		"Data\\Map\\Cutman\\objects.txt",
		"Data\\Map\\Cutman\\quadtree.txt"
		);
	tilemap.initStage("Data\\Map\\Cutman\\stage5.txt");
}

void MGMGame::update()
{
	tilemap.update();

}
void MGMGame::render()
{
	tilemap.render();
	Rockman::getInstance()->render();
}


MGMGame::~MGMGame(void)
{
}
