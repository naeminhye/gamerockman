#include "CutmanMap.h"
#include "CutmanScissors.h"


Stage * CutmanMap::findNextStageOnDoor()
{
	if (Stage::curStage->index == 5)
		return stages[9];
	return stages[Stage::curStage->index + 1];
}

void CutmanMap::render()
{
	Map::render();
	CutmanScissors::getInstance()->render();
}

void CutmanMap::update()
{
	CutmanScissors::getInstance()->update();
	Map::update();
	CutmanScissors::getInstance()->updateLocation();

}

CutmanMap::CutmanMap()
{
	init("Data\\Map\\Cutman\\tileSheet.png", "Data\\Map\\Cutman\\matrix.txt",
		"Data\\Map\\Cutman\\objects.txt",
		"Data\\Map\\Cutman\\quadtree.txt"
	);
	initStage("Data\\Map\\Cutman\\stageBoss.txt");
}


CutmanMap::~CutmanMap()
{
}
