#pragma once
#include "SpriteManager.h"
#include "MGMGameTime.h"

class SelectMapFrame
{
public:
	// toa do
	float x, y;

	// dia chi sprite
	Sprite* sprite;
	int action, frameIndex;
	MGMGameTime delay;


	void update();
	void render();
	SelectMapFrame();
	~SelectMapFrame();
};

