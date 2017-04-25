#include "QuadNode.h"

QuadNode::QuadNode(ifstream & fs, BaseObject** allObjects, int mapHeight)
{
	TL = TR = BL = BR = 0;
	fs >> id;
	fs >> x >> y >> width >> height;
	y = mapHeight - y;
	int nNodes;
	fs >> nNodes >> nObject;

	if (nNodes == 4)
	{
		//loai 1: Node chua 4 node con, ko chua doi tuong
		TL = new QuadNode(fs, allObjects, mapHeight);
		TR = new QuadNode(fs, allObjects, mapHeight);
		BL = new QuadNode(fs, allObjects, mapHeight);
		BR = new QuadNode(fs, allObjects, mapHeight);
		return;
	}

	if (nObject > 0)
	{
		int objectIndex;
		//loai 2: Node ko chua node con nhung co doi tuong
		objectsInNode = new BaseObject*[nObject];
		for (size_t i = 0; i < nObject; i++)
		{
			fs >> objectIndex;
			objectsInNode[i] = allObjects[objectIndex];
		}
	}

	//loai 3
}
//do doi tuong vao camera
void QuadNode::fillObjectToCamera()
{
	if (!Collision::AABBCheck(this, MGMCamera::getInstance()))
	{
		return;
	}
	//loai 1
	if (TL != 0)
	{
		TL->fillObjectToCamera();
		TR->fillObjectToCamera();
		BL->fillObjectToCamera();
		BR->fillObjectToCamera();
		return;
	}

	//loai 2
	if (nObject > 0)
	{
		for (size_t i = 0; i < nObject; i++)
		{
			MGMCamera::getInstance()->objects.addObject(objectsInNode[i]);
		}
	}
}

QuadNode::~QuadNode()
{
}
