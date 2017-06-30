#pragma once
#include "Texture.h"
class SelectRockmanBoard
{
public:
	float x, y; // toa do

	Texture* img;
	void render();
	SelectRockmanBoard();
	~SelectRockmanBoard();
};

