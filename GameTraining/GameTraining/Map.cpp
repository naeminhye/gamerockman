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
#include "FlyingShell.h"
#include "RockmanDeath.h"
#include "BigEye.h"
#include "ScrewBomber.h"
#include "Cutman.h"
#include "Door.h"
#include "Met.h"
#include "Trundle.h"
#include "Bridge.h"
#include "PicketBullet.h"
#include "Death.h"
#include "Item.h"
#include "DeathHole.h"
#include "Spike.h"
#include "CutmanScissors.h"
#include "Gutsman.h"
#include "GutsmanRock.h"
#include "GutsmanBrokenRock.h"
#include "NumberSprite.h"

extern Blader* test;

Map* Map::curMap=0;
bool Map::onStageChangeByDoor = false;

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

	Camera* camera = Camera::getInstance();
	Rockman* rockman = Rockman::getInstance();

	ignoreLineIfstream(fs, 3);
	fs >> camera->x >> camera->y;
	camera->y = rowCount * 16 - camera->y;
	ignoreLineIfstream(fs, 3);
	fs >> rockman->x >> rockman->y;
	rockman->y = rowCount * 16 - rockman->y;
	ignoreLineIfstream(fs, 3);
	fs >> stageBeginIndex;
	stageBegin = stageBeginIndex;

	cameraBeginX = camera->x;
	cameraBeginY = camera->y;
	rmBeginX = rockman->x;
	rmBeginY = rockman->y;

	if (Stage::curStage == 0)
	{
		Stage::curStage = stages[stageBeginIndex];
	}
}

void Map::updateStageChangeNext()
{
	auto nextStage = stages.at(Stage::curStage->index + 1);
	Camera* camera = Camera::getInstance();
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
	Camera* camera = Camera::getInstance();
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

void Map::updateStageChangeByDoor()
{
	Stage* nextStage;
	Camera* camera;
	Door::doorDelay.update();
	switch (Door::doorActivity)
	{
	case DOOR_WAITING_TO_OPEN:
		if (Door::doorDelay.isTerminated())
		{
			Door::doorActivity = DOOR_OPENING;
			Door::currentDoor->setAction(DOOR_OPEN);
			Door::currentDoor->pauseAnimation = false;
		}
		break;
	case DOOR_OPENING:
		Door::currentDoor->update();
		break;
	case DOOR_CAMERA_CHANGING:
		camera = Camera::getInstance();
		camera->dx = DOOR_CAMERA_CHANGING_DX;
		//tim next stage
		nextStage = findNextStageOnDoor();
		if (camera->x + camera->dx > nextStage->left())
		{
			camera->x = nextStage->left();
			camera->dx = 0;

			Door::doorActivity = DOOR_CLOSING;
			Door::currentDoor->setAction(DOOR_CLOSE);
			Door::currentDoor->pauseAnimation = false;
			Stage::curStage = nextStage;
		}
		else
		{
			camera->x += camera->dx;
			Rockman::getInstance()->x += 1;
			Rockman::getInstance()->dx = 0;
			Rockman::getInstance()->vx = 0;
			Rockman::getInstance()->BaseObject::update();
		}
		break;
	case DOOR_CLOSING:
		Door::currentDoor->update();
		break;
	default:
		break;
	}
}

Stage * Map::findNextStageOnDoor()
{
	return stages[Stage::curStage->index + 1];
}

void Map::readObjects(char * objectsPath)
{
	int id;;
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
		case SPR_CUTTER:
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
		case SPR_SHELL:
			objects[i] = new FlyingShell();
			break;
		case SPR_BOMBER:
			objects[i] = new ScrewBomber();
			break;
		case SPR_EYE:
			objects[i] = new BigEye();
			break;
		case SPR_CUTMAN:
			objects[i] = new Cutman();
			break;
		case SPR_DOOR:
			objects[i] = new Door();
			break;
		case SPR_MET:
			objects[i] = new Met();
			break;
		case SPR_TRUNDLE:
			objects[i] = new Trundle();
			break;
		case SPR_PICKET:
			objects[i] = new Picket();
			break;
		case SPR_BRIDGE:
			objects[i] = new Bridge();
			break;
		case SPR_SPIKE:
			objects[i] = new Spike();
			break;
		case SPR_DEATH_HOLE:
			objects[i] = new DeathHole();
			break;
		case SPR_GUTSMAN:
			objects[i] = new Gutsman();
			break;
		case SPR_GUTSMAN_BROKEN_ROCK:
			objects[i] = new GutsmanBrokenRock();
			break;
			//TODO: Them doi tuong nho them vao day
		default:
			objects[i] = new BaseObject();
			break;
		}
		objects[i]->id = id;
		fs >> objects[i]->x
			>> objects[i]->y
			>> objects[i]->width
			>> objects[i]->height;



		objects[i]->y = rowCount * 16 - objects[i]->y;

		objects[i]->oldRect.x = objects[i]->x;
		objects[i]->oldRect.y = objects[i]->y;
		objects[i]->oldRect.width = objects[i]->width;
		objects[i]->oldRect.height = objects[i]->height;

		if (id >= 0)
		{
			objects[i]->sprite = SpriteManager::getInstance()->sprites[id % 100];
			auto mov = (MovableObject*)objects[i];
			fs >> mov->spaceMove.x
				>> mov->spaceMove.y
				>> mov->spaceMove.width
				>> mov->spaceMove.height;
			mov->spaceMove.y = rowCount * 16 - mov->spaceMove.y;
		}

		objects[i]->init();
	}
}

void Map::update()
{

	bool keyEnterPress = KEY::getInstance()->isEnterPress;
	// TODO them Pause button
	if (keyEnterPress && !isPause)
	{
		isPause = true;
		isChangingType = true;
	}
	else if (keyEnterPress && isPause)
	{
		isPause = false;
		isChangingType = false;
	}

	if (isPause)
	{
		return;
	}

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

	if (onStageChangeByDoor)
	{
		updateStageChangeByDoor();
		return;
	}

	auto camera = Camera::getInstance();

	Rockman::getInstance()->update();

	//tao danh sach object trong camera
	quadtree->update();

	int nObjectsCam = Camera::getInstance()->objects.allObjects.size();
	auto allObjectsInCam = &Camera::getInstance()->objects.allObjects;

	int nEnemyObjectsCam = Camera::getInstance()->objects.enemies.size();
	auto enemiesInCam = &Camera::getInstance()->objects.enemies;

	int nStair = Camera::getInstance()->objects.stairs.size();
	auto stairsInCam = &Camera::getInstance()->objects.stairs;

	int nSpace = Camera::getInstance()->objects.outerSpaces.size();
	auto spacesInCam = &Camera::getInstance()->objects.outerSpaces;

	int nGroundObjectsCam = Camera::getInstance()->objects.grounds.size();
	auto groundsInCam = &Camera::getInstance()->objects.grounds;

	int nTrundle = Camera::getInstance()->objects.trundles.size();
	auto trundlesInCam = &Camera::getInstance()->objects.trundles;

	int nBridge = Camera::getInstance()->objects.bridges.size();
	auto bridgesInCam = &Camera::getInstance()->objects.bridges;

	// update tat ca cac doi tuong trong camera
	for (size_t i = 0; i < nObjectsCam; i++)
	{
		auto obj = allObjectsInCam->at(i);
		obj->update();
	}

	// kiem tra va cham Rockman voi tat ca cac doi tuong cau thang trong camera
	for (size_t i = 0; i < nStair; i++)
	{
		auto obj = stairsInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), obj);
	}

	// kiem tra va cham giua Rockman voi tat ca cac doi tuong Ground trong camera
	for (size_t i = 0; i < nGroundObjectsCam; i++)
	{
		auto obj = groundsInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), obj);
		Collision::CheckCollision(CutmanScissors::getInstance(), obj);
	}

	for (size_t i = 0; i < nEnemyObjectsCam; i++)
	{
		auto enemy = enemiesInCam->at(i);
		// kiem tra va cham cua tat ca cac Enemies trong camera voi Rockman
		Collision::CheckCollision(Rockman::getInstance(), enemy);
		for (size_t j = 0; j < nGroundObjectsCam; j++)
		{
			// kiem tra va cham cua tat ca cac Enemies trong camera voi Ground
			Collision::CheckCollision(enemy, groundsInCam->at(j));
		}
	}

	for (size_t i = 0; i < nEnemyObjectsCam; i++)
	{
		auto enemy = enemiesInCam->at(i);
		// update vi tri cua tat ca cac Enemies trong Camera
		enemy->updateLocation();
	}


	for (size_t i = 0; i < nTrundle; i++)
	{
		auto obj = trundlesInCam->at(i);
		Collision::CheckCollision(Rockman::getInstance(), obj);
		for (size_t j = 0; j < nBridge; j++)
		{
			Collision::CheckCollision(obj, bridgesInCam->at(j));
		}
	}

	for (size_t i = 0; i < nTrundle; i++)
	{
		auto obj = trundlesInCam->at(i);
		obj->updateLocation();
	}


	for (size_t i = 0; i < RockmanBullet::bullets->Count; i++)
	{
		RockmanBullet::bullets->at(i)->update();
		RockmanBullet::bullets->at(i)->updateLocation();

		for (size_t j = 0; j < nEnemyObjectsCam; j++)
		{
			auto enemy = enemiesInCam->at(j);
			Collision::CheckCollision(RockmanBullet::bullets->at(i), enemy);

		}

		if (!Collision::AABBCheck(Camera::getInstance(), RockmanBullet::bullets->at(i)) || RockmanBullet::bullets->at(i)->canDelete)
		{
			RockmanBullet::bullets->at(i)->deleteBullet();
			i--;
		}
	}

	for (size_t i = 0; i < BeakBullet::bullets->Count; i++)
	{
		auto obj = BeakBullet::bullets->at(i);
		Collision::CheckCollision(Rockman::getInstance(), obj);
		obj->updateLocation();
		if (!Collision::AABBCheck(Camera::getInstance(), obj))
		{
			obj->deleteBullet();
			i--;
		}
	}

	for (size_t i = 0; i < PicketBullet::bullets->Count; i++)
	{
		PicketBullet::bullets->at(i)->update();
		PicketBullet::bullets->at(i)->updateLocation();
		if (!Collision::AABBCheck(Camera::getInstance(), PicketBullet::bullets->at(i)))
		{
			PicketBullet::bullets->at(i)->deleteBullet();
			i--;
		}
	}

	for (size_t i = 0; i < SuperCutterBullet::bullets->Count; i++)
	{
		auto obj = SuperCutterBullet::bullets->at(i);
		obj->update();
		Collision::CheckCollision(Rockman::getInstance(), obj);
		obj->updateLocation();
		if (!Collision::AABBCheck(Camera::getInstance(), obj))
		{
			obj->deleteBullet();
			i--;
		}
	}

	for (size_t i = 0; i < RockmanDeath::deads->Count; i++)
	{
		RockmanDeath::deads->at(i)->update();
		RockmanDeath::deads->at(i)->updateLocation();
		if (!Collision::AABBCheck(Camera::getInstance(), RockmanDeath::deads->at(i)))
		{
			RockmanDeath::deads->at(i)->deleteDead();
			i--;
		}
	}

	for (size_t i = 0; i < GutsmanBrokenRock::rocks->Count; i++)
	{
		auto obj = GutsmanBrokenRock::rocks->at(i);
		obj->update();
		Collision::CheckCollision(Rockman::getInstance(), obj);
		obj->updateLocation();
		if (!Collision::AABBCheck(Camera::getInstance(), obj))
		{
			obj->deleteRock();
			i--;
		}
	}


	for (size_t i = 0; i < Death::deaths->Count; i++)
	{
		Death::deaths->at(i)->update();
	}


	for (size_t i = 0; i < Item::items->Count; i++)
	{
		if (i >= Item::items->Count)
		{
			break;
		}
		auto item = Item::items->at(i);
		item->update();
		int j = 0;
		for (j = 0; j < nGroundObjectsCam; j++)
		{
			Collision::CheckCollision(item, groundsInCam->at(j));
			if (Collision::AABBCheck(groundsInCam->at(j), item))
			{
				item->release();
				i--;
				break;
			}
		}
		if (j < nGroundObjectsCam)
			continue;
		item->updateLocation();
		if (Collision::AABBCheck(Rockman::getInstance(), Item::items->at(i)))
		{
			item->release();
			//item->onIntersect(Rockman::getInstance());
			i--;
			continue;
		}
	}
	Rockman::getInstance()->updateLocation();
	camera->update();
	for (size_t i = 0; i < nSpace; i++)
	{
		auto obj = spacesInCam->at(i);
		Collision::CheckCollision(Camera::getInstance(), obj);
	}
	camera->updateLocation();

}

void Map::render()
{
	TileMap::render();
	if (onStageChangeNext || onStageChangePrev)
		return;
	int nObjectsCam = Camera::getInstance()->objects.allObjects.size();
	auto allObjectsInCam = &Camera::getInstance()->objects.allObjects;

	for (size_t i = 0; i < nObjectsCam; i++)
	{
		allObjectsInCam->at(i)->render();
	}

	for (size_t i = 0; i < BeakBullet::bullets->Count; i++)
	{
		BeakBullet::bullets->at(i)->render();
	}

	for (size_t i = 0; i < PicketBullet::bullets->Count; i++)
	{
		PicketBullet::bullets->at(i)->render();
	}


	for (size_t i = 0; i < RockmanBullet::bullets->Count; i++)
	{
		RockmanBullet::bullets->at(i)->render();
	}

	for (size_t i = 0; i < SuperCutterBullet::bullets->Count; i++)
	{
		SuperCutterBullet::bullets->at(i)->render();
	}

	for (size_t i = 0; i < RockmanDeath::deads->Count; i++)
	{
		RockmanDeath::deads->at(i)->render();
	}


	for (size_t i = 0; i < Death::deaths->Count; i++)
	{
		Death::deaths->at(i)->render();
	}

	for (size_t i = 0; i < Item::items->Count; i++)
	{
		Item::items->at(i)->render();
	}

	// TODO ThemDan st2: Nhớ vẽ khi thêm đối tượng nhé <3
	int clearPointX = (BACKBUFFER_WIDTH / 2) - (54 / 2);
	NumberSprite::getInstance()->render(clearPointX, 25, 6, 54612);


}

Map::Map()
{
	onStageChangeNext = false;
	onStageChangePrev = false;
	curMap = this;
	isPause = false;
	isChangingType = false;

}


Map::~Map()
{
}
