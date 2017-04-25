#pragma once
#include"QuadNode.h"
class QuadTree
{
public:
	QuadNode* rootNode;
	QuadTree(char* quadTreePath, BaseObject** allObjects, int mapHeight);
	~QuadTree();

	void update();
	void removeObjects();
	void fillObject();

};

