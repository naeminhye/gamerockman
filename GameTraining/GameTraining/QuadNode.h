#pragma once
#include "FRectangle.h"
#include<fstream>
#include"Collision.h"
#include"BaseObject.h"
#include"MGMCamera.h"
using namespace std;
class QuadNode :
	public FRectangle
{
public:

	QuadNode* TL,* BL,* TR,* BR;
	int id;
	int nObject;
	BaseObject** objectsInNode;
	
	QuadNode(ifstream &fs, BaseObject** allObjects,int mapHeight);
	
	void fillObjectToCamera();

	~QuadNode();
};

