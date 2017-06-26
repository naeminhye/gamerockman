#include "GutsmanMap.h"
#include "Gutsman.h"
#include "GutsmanRock.h"

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
	initStage("Data\\Map\\Gutsman\\stageBoss.txt");
	GameSound::getInstance()->stop(SOUND_STAGE_SELECT);
	GameSound::getInstance()->play(SOUND_GUTSMAN);
}


GutsmanMap::~GutsmanMap()
{
}

void GutsmanMap::update()
{
	Map::update();
	GutsmanRock::getInstance()->update();
	Collision::CheckCollision(GutsmanRock::getInstance(), Gutsman::instance);
	GutsmanRock::getInstance()->updateLocation();
}

void GutsmanMap::render()
{
	Map::render();
	GutsmanRock::getInstance()->render();
}
