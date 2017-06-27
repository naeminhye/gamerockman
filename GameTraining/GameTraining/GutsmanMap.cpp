#include "GutsmanMap.h"
#include "Gutsman.h"
#include "GutsmanRock.h"
#include "GutsmanBrokenRock.h"

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
	//GameSound::getInstance()->stop(SOUND_STAGE_SELECT);
	GameSound::getInstance()->play(SOUND_GUTSMAN);
}


GutsmanMap::~GutsmanMap()
{
}

void GutsmanMap::update()
{
	/*for (size_t i = 0; i < GutsmanBrokenRock::rocks->Count; i++)
	{
		GutsmanBrokenRock::rocks->at(i)->update();
		GutsmanBrokenRock::rocks->at(i)->updateLocation();
		if (!Collision::AABBCheck(Camera::getInstance(), GutsmanBrokenRock::rocks->at(i)))
		{
			GutsmanBrokenRock::rocks->at(i)->deleteRock();
			i--;
		}
	}*/

	Map::update();

	int nGroundObjectsCam = Camera::getInstance()->objects.grounds.size();
	auto groundsInCam = &Camera::getInstance()->objects.grounds;
	

	GutsmanRock::getInstance()->update();
	Collision::CheckCollision(GutsmanRock::getInstance(), Gutsman::instance);
	for (int i = 0; i < nGroundObjectsCam; i++)
	{
		Collision::CheckCollision(GutsmanRock::getInstance(), groundsInCam->at(i));
	}
	Collision::CheckCollision(GutsmanRock::getInstance(), Rockman::getInstance());


	GutsmanRock::getInstance()->updateLocation();
}

void GutsmanMap::render()
{
	Map::render();
	GutsmanRock::getInstance()->render();

	for (size_t i = 0; i < GutsmanBrokenRock::rocks->Count; i++)
	{
		GutsmanBrokenRock::rocks->at(i)->render();
	}
}
