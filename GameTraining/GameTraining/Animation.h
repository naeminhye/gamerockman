#pragma once
#include <Windows.h>
#include "MGMGameTime.h"

class Animation
{
public:
	RECT* frames;
	int frameCount;

	Animation();
	~Animation();
	void next(int &index);
};

