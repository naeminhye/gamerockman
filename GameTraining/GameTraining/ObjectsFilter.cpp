#include "ObjectsFilter.h"
#include"BaseObject.h"
#include"Stage.h"



void ObjectsFilter::addObject(BaseObject * object)
{
	if (!Collision::AABBCheck(object, Stage::curStage))
		return;

	//if (!Collision::AABBCheck(object, MGMCamera::getInstance()) && object->collisionType!=CT_OUTERSPACE)
	//	return;
	allObjects._Add(object);
	switch (object->collisionType)
	{
	case CT_DOOR:
	case CT_GROUND:
		grounds._Add(object);
		break;
	case CT_STAIR:
		stairs._Add(object);
		break;
	case CT_ENEMY:
		enemies._Add(object);
		break;
	case CT_ITEM:
		items._Add(object);
		break;
	case CT_OUTERSPACE:
		outerSpaces._Add(object);
		break;
	case CT_TRUNDLE:
		trundles._Add(object);
		break;
	case CT_BRIDGE:
		bridges._Add(object);
		break;
	default:
		break;
	}
}

void ObjectsFilter::removeObject(BaseObject * object)
{
	allObjects._Remove(object);
	switch (object->collisionType)
	{
	case CT_DOOR:
	case CT_GROUND:
		grounds._Remove(object);
		break;
	case CT_STAIR:
		stairs._Remove(object);
		break;
	case CT_ENEMY:
		enemies._Remove(object);
		break;
	case CT_ITEM:
		items._Remove(object);
		break;
	case CT_OUTERSPACE:
		outerSpaces._Remove(object);
		break; 
	case CT_TRUNDLE:
		trundles._Remove(object);
		break;
	case CT_BRIDGE:
		bridges._Remove(object);
		break;
	default:
		break;
	}
}

void ObjectsFilter::clear()
{
	allObjects.Clear();
	grounds.Clear();
	enemies.Clear();
	outerSpaces.Clear();
	items.Clear();
}

ObjectsFilter::ObjectsFilter()
{
}


ObjectsFilter::~ObjectsFilter()
{
}
