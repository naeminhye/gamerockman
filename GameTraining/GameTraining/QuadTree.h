#pragma once
#include"QuadNode.h"
class QuadTree
{
public:
	QuadNode* rootNode;

	void update();
	void removeObjects();
	void fillObject();

	/* CONSTRUCTOR & DESTRUCTOR */
	QuadTree(char* quadTreePath, BaseObject** allObjects, int mapHeight);
	~QuadTree();



};

