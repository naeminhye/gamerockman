#include "CutmanMap.h"



Stage * CutmanMap::findNextStageOnDoor()
{
	if (Stage::curStage->index == 5)
		return stages[9];
	return stages[Stage::curStage->index + 1];
}

CutmanMap::CutmanMap()
{
	init("Data\\Map\\Cutman\\tileSheet.png", "Data\\Map\\Cutman\\matrix.txt",
		"Data\\Map\\Cutman\\objects.txt",
		"Data\\Map\\Cutman\\quadtree.txt"
	);
	initStage("Data\\Map\\Cutman\\stage62.txt");
}


CutmanMap::~CutmanMap()
{
}
