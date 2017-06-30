#pragma once
#include "List.h"
#include "FRectangle.h"
#include <fstream>

using namespace std;

class Stage : public FRectangle
{
public:
	int index; 
	static Stage* curStage;

	int cameraBeginX, cameraBeginY;
	int rmBeginX, rmBeginY;

	void setLocation(int camX, int camY, int rmX, int rmY);

	/* CONSTRUCTOR & DESTRUCTOR */	
	Stage(ifstream &fs);
	~Stage();

};

