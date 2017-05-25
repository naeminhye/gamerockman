#pragma once
#include"List.h"
class BaseObject;
class ObjectsFilter
{
public:
	List<BaseObject*> grounds;
	List<BaseObject*> enemies;
	List<BaseObject*> stairs;
	List<BaseObject*> items;
	List<BaseObject*> outerSpaces;
	List<BaseObject*> trundles;
	List<BaseObject*> bridges;
	List<BaseObject*> allObjects;
	void addObject(BaseObject* object);
	void removeObject(BaseObject* object);
	void clear();
	ObjectsFilter();
	~ObjectsFilter();
};

