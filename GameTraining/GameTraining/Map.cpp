#include"KEY.h"
#include "Map.h"
#include"Picket.h"
#include"Blader.h"
#include"Beak.h"
#include"Rockman.h"
#include"Collision.h"
#include"Stairs.h"
#include"OuterSpace.h"
#include"RockmanBullet.h"
#include "OctopusBattery.h"
#include "SuperCutter.h"
#include "Flea.h"
void Map::init(char * tileSheetPath, char * matrixPath, char * objectsPath, char* quadTreePath)
{
	TileMap::init(tileSheetPath, matrixPath);
	readObjects(objectsPath);
	quadtree = new QuadTree(quadTreePath, objects, rowCount * 16);
}

void Map::initStage(char * stagePath)
{
	int count, stageBeginIndex;
	ifstream fs(stagePath);
	Stage* stage;
	ignoreLineIfstream(fs, 1);
	fs >> count;
	ignoreLineIfstream(fs, 3);
	for (int i = 0; i < count; i++)
	{
		stage = new Stage(fs);
		stages._Add(stage);
		stage->y = rowCount * 16 - stage->y;
	}

	MGMCamera* camera = MGMCamera::getInstance();
	Rockman* rockman = Rockman::getInstance();

	ignoreLineIfstream(fs, 3);
	fs >> camera->x >> camera->y;
	camera->y = rowCount * 16 - camera->y;
	ignoreLineIfstream(fs, 3);
	fs >> rockman->x >> rockman->y;
	rockman->y = rowCount * 16 - rockman->y;
	ignoreLineIfstream(fs, 3);
	fs >> stageBeginIndex;


	if (Stage::curStage == 0)
	{
		Stage::curStage = stages[stageBeginIndex];
	}
}

void Map::updateStageChangeNext()
{
	auto nextStage = stages.at(Stage::curStage->index + 1);
	MGMCamera* camera = MGMCamera::getInstance();
	camera->dy = CAMERA_CHANGESTAGE_DY;
	if (camera->bottom() + camera->dy > nextStage->bottom())
	{
		camera->y = nextStage->bottom() + camera->height;
		camera->dy = 0;
		onStageChangeNext = false;
		Stage::curStage = nextStage;//****
		return;
	}
	Rockman* rockman = Rockman::getInstance();
	rockman->y += ROCKMAN_CHANGESTAGE_DY;
	rockman->pauseAnimation = false;
	rockman->BaseObject::update();
	camera->updateLocation();
}

void Map::updateStageChangePrev()
{
	auto prevStage = stages.at(Stage::curStage->index - 1);
	MGMCamera* camera = MGMCamera::getInstance();
	camera->dy = -CAMERA_CHANGESTAGE_DY;
	if (camera->bottom() + camera->dy < prevStage->bottom())
	{
		camera->y = prevStage->bottom() + camera->height;
		camera->dy = 0;
		onStageChangePrev = false;
		Stage::curStage = prevStage;
		return;
	}
	Rockman* rockman = Rockman::getInstance();
	if (rockman->onStair)
	{
		rockman->y += -ROCKMAN_CHANGESTAGE_DY;
		rockman->pauseAnimation = false;
		rockman->BaseObject::update();
	}
	camera->updateLocation();
}

void Map::readObjects(char * objectsPath)
{
	int id;
	ifstream fs(objectsPath);
	fs >> nObject;
	objects = new BaseObject*[nObject];
	for (auto i = 0; i < nObject; i++)
	{
		fs >> id;
		switch (id % 100)
		{
		case SPR_BLADER:
			objects[i] = new Blader();
			break;
		case SPR_BEAK:
			objects[i] = new Beak();
			break;
		case SPR_FLEA:
			objects[i] = new Flea();
			break;
		case SPR_SUPERCUTTER:
			objects[i] = new SuperCutter();
			break;
		case SPR_STAIR:
			objects[i] = new Stairs();
			break;
		case SPR_OUTERSPACE:
			objects[i] = new OuterSpace();
			break;
		case SPR_OCTOPUS:
			objects[i] = new OctopusBattery();
			break;
		default:
			objects[i] = new BaseObject();
			break;
		}
		objects[i]->id = id;
		fs >> objects[i]->x
			>> objects[i]->y
			>> objects[i]->width
			>> objects[i]->height;

		objects[i]->init();

		objects[i]->y = rowCount * 16 - objects[i]->y;

		objects[i]->oldRect.x = objects[i]->x;
		objects[i]->oldRect.y = objects[i]->y;
		objects[i]->oldRect.width = objects[i]->width;
		objects[i]->oldRect.height = objects[i]->height;

		if (id >= 0)
		{
			objects[i]->sprite = SpriteManager::getInstance()->sprites[id%100];
			auto mov = (MovableObject*)objects[i];
			fs >> mov->spaceMove.x
				>> mov->spaceMove.y
				>> mov->spaceMove.width
				>> mov->spaceMove.height;
			mov->spaceMove.y = rowCount * 16 - mov->spaceMove.y;
		}
	}
}

void Map::update()
{
	if (!onStageChangeNext && Rockman::getInstance()->checkChangeNextStage(&stages))
	{
		onStageChangeNext = true;
	}
	if (!onStageChangePrev && Rockman::getInstance()->checkChangePrevStage(&stages))
	{
		onStageChangePrev = true;
	}

	if (onStageChangeNext)
	{
		updateStageChangeNext();
		return;
	}
	if (onStageChangePrev)
	{
		updateStageChangePrev();
		return;
	}
	auto camera = MGMCamera::getInstance();

	Rockman::getInstance()->update();

	//tao danh sach object trong camera
	quadtree->update();

	int nObjectsCam = MGMCamera::getInstance()->objects.allObjects.size();
	auto allObjectsInCam = &MGMCamera::getInstance()->objects.allObjects;

	int nEnemyObjectsCam = MGMCamera::getInstance()->objects.enemies.size();
	auto enemiesInCam = &MGMCamera::getInstance()->objects.enemies;

	int nStair = MGMCamera::getInstance()->objects.stairs.size();
	auto stairsInCam = &MGMCamera::getInstance()->objects.stairs;

	int nSpace = MGMCamera::getInstance()->objects.outerSpaces.size();
	auto spacesInCam = &MGMCamera::getInstance()->objects.outerSpaces;

	int nGroundObjectsCam = MGMCamera::getInstance()->objects.grounds.size();
	auto groundsInCam = &MGMCamera::getInstance()->objects.grounds;

	for (size_t i = 0; i < nObjectsCam; i++)
	{
		auto obj = allObjectsInCam->at(i);
		obj->update();
	}

	for (size_t i = 0; i < nStair; i++)
	{
		auto obj = stairsInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), obj);
	}
	for (size_t i = 0; i < nGroundObjectsCam; i++)
	{
		auto obj = groundsInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), obj);
	}

	for (size_t i = 0; i < nEnemyObjectsCam; i++)
	{
		auto enemy = enemiesInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), enemy);
		for (size_t j = 0; j < nGroundObjectsCam; j++)
		{
			Collision::CheckCollision(enemy, groundsInCam->at(j));
		}
	}

	for (size_t i = 0; i < nEnemyObjectsCam; i++)
	{
		auto enemy = enemiesInCam->at(i);
		enemy->updateLocation();
	}

	Rockman::getInstance()->updateLocation();
	camera->update();

	for (size_t i = 0; i < nSpace; i++)
	{
		auto obj = spacesInCam->at(i);
		Collision::CheckCollision(MGMCamera::getInstance(), obj);
	}

	camera->updateLocation();
	for (size_t i = 0; i < RockmanBullet::bullets->Count; i++)
	{
		RockmanBullet::bullets->at(i)->updateLocation();
		if (!Collision::AABBCheck(MGMCamera::getInstance(), RockmanBullet::bullets->at(i)))
		{
			RockmanBullet::bullets->at(i)->deleteBullet();
			i--;
		}
	}

	for (size_t i = 0; i < BeakBullet::bullets->Count; i++)
	{
		BeakBullet::bullets->at(i)->updateLocation();
	}

	for (size_t i = 0; i < SuperCutterBullet::bullets->Count; i++)
	{
		SuperCutterBullet::bullets->at(i)->update();
		SuperCutterBullet::bullets->at(i)->updateLocation();

	}
}

void Map::render()
{
	TileMap::render();
	if (onStageChangeNext || onStageChangePrev)
		return;
	int nObjectsCam = MGMCamera::getInstance()->objects.allObjects.size();
	auto allObjectsInCam = &MGMCamera::getInstance()->objects.allObjects;

	for (size_t i = 0; i < nObjectsCam; i++)
	{
		allObjectsInCam->at(i)->render();
	}

	for (size_t i = 0; i < BeakBullet::bullets->Count; i++)
	{
		BeakBullet::bullets->at(i)->render();
	}

	for (size_t i = 0; i < RockmanBullet::bullets->Count; i++)
	{
		RockmanBullet::bullets->at(i)->render();
	}

	for (size_t i = 0; i < SuperCutterBullet::bullets->Count; i++)
	{
		SuperCutterBullet::bullets->at(i)->render();
	}

	// TODO ThemDan st2: Nhớ vẽ khi thêm đối tượng nhé <3
}

Map::Map()
{
	onStageChangeNext = false;
	onStageChangePrev = false;
}


Map::~Map()
{
}
