#pragma once
#include "MGMTexture.h"
class SelectRockmanBoard
{
public:
	float x, y; // toa do

	MGMTexture* img;
	void render();
	SelectRockmanBoard();
	~SelectRockmanBoard();
};

