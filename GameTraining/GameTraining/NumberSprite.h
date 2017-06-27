#pragma once
#include "Sprite.h"
class NumberSprite :
	public Sprite
{
public:

	static NumberSprite* instance;
	static NumberSprite* getInstance();

	void render(int x, int y, int num, int clearPoint);

	NumberSprite();
	~NumberSprite();
};

