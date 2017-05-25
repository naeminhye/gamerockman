#include "GutsmanMap.h"



Stage * GutsmanMap::findNextStageOnDoor()
{
	if (Stage::curStage->index == 2)
		return stages[0];
	return stages[Stage::curStage->index + 1];
}

GutsmanMap::GutsmanMap()
{
	init("Data\\Map\\Gutsman\\tileSheet.png", "Data\\Map\\Gutsman\\matrix.txt",
		"Data\\Map\\Gutsman\\objects.txt",
		"Data\\Map\\Gutsman\\quadtree.txt"
	);
	initStage("Data\\Map\\Gutsman\\stage12.txt");
}


GutsmanMap::~GutsmanMap()
{
}
