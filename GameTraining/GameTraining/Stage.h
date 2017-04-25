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
	Stage(ifstream &fs); 
	
	~Stage();
};

