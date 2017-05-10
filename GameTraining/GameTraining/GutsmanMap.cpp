#include "GutsmanMap.h"



GutsmanMap::GutsmanMap()
{
	init("Data\\Map\\Gutsman\\tileSheet.png", "Data\\Map\\Gutsman\\matrix.txt",
		"Data\\Map\\Gutsman\\objects.txt",
		"Data\\Map\\Gutsman\\quadtree.txt"
	);
	initStage("Data\\Map\\Gutsman\\stage1.txt");
}


GutsmanMap::~GutsmanMap()
{
}
