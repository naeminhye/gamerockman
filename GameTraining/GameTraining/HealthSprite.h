#pragma once
#include "Sprite.h"
class HealthSprite :
	public Sprite
{
public:
	static HealthSprite* instance;
	static HealthSprite* getInstance();
	void render(int left, int bottom, int healthCount, int maxHealth);

	/* CONSTRUCTOR & DESTRUCTOR */
	HealthSprite();
	~HealthSprite();

	int height;
};

