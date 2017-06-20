#pragma once
#include "SpriteManager.h"
#include "GameTime.h"

class SelectMapFrame
{
public:
	float x, y; // toa do
	Sprite* sprite; // dia chi sprite
	int action, frameIndex;
	GameTime delay;

	void update();
	void render();
	
	/* CONSTRUCTOR & DESTRUCTOR */
	SelectMapFrame();
	~SelectMapFrame();

};

