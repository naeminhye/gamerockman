#pragma once
#include "Sprite.h"
class ClearPointSprite :
	public Sprite
{
public:

	static ClearPointSprite* instance;
	static ClearPointSprite* getInstance();

	void render(int left, int bottom, int clearPoint);

	ClearPointSprite();
	~ClearPointSprite();
};

