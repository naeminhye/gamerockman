#include "QuadTree.h"
#include"Blader.h"
extern Blader* test;

extern void ignoreLineIfstream(ifstream& fs, int lineCount);

QuadTree::QuadTree(char * quadTreePath, BaseObject ** allObjects, int mapHeight)
{
	ifstream fs(quadTreePath);
	ignoreLineIfstream(fs, 1);
	rootNode = new QuadNode(fs, allObjects, mapHeight);
}

QuadTree::~QuadTree()
{
}

void QuadTree::update() //***
{

	List<BaseObject*>* allObjects =  &MGMCamera::getInstance()->objects.allObjects;
	for (int i = 0; i < allObjects->Count; i++)
	{
		auto obj = allObjects->at(i);
		if (!Collision::AABBCheck(MGMCamera::getInstance(), obj) && !Collision::AABBCheck(MGMCamera::getInstance(), &(obj->oldRect)))
		{
			obj->restoreLocation();
		}

	}

	//xoa doi tuong trong camera
	removeObjects();
	//do doi tuong vao camera
	fillObject();
}

void QuadTree::removeObjects()
{
	MGMCamera::getInstance()->objects.clear();
}

void QuadTree::fillObject()
{
	rootNode->fillObjectToCamera();
}
