#pragma once
#include "FRectangle.h"
#include<fstream>
#include"Collision.h"
#include"BaseObject.h"
#include"Camera.h"
using namespace std;
class QuadNode :
	public FRectangle
{
public:
	int id;
	int nObject;

	QuadNode* TL,* BL,* TR,* BR;
	BaseObject** objectsInNode;
	void fillObjectToCamera();

	/* CONSTRUCTOR & DESTRUCTOR */
	QuadNode(ifstream &fs, BaseObject** allObjects,int mapHeight);
	~QuadNode();
};

