#pragma once
#include"Sprite.h"

enum SPRITE_INFO
{
	//add
	SPR_OUTERSPACE = -3,
	SPR_STAIR = -2,
	SPR_ROCKMAN = 0, //= 0
	SPR_BLADER, // = 1
	SPR_PICKET,
	SPR_PEA, //= 3
	SPR_BEAK, // = 4
	SPR_LINH, //= 5
	SPR_BULLET, // = 6
	SPR_BEAK_BULLET,

	SPR_COUNT //= so luong sprite
};



class SpriteManager
{
public:
	static SpriteManager* instance;
	static SpriteManager* getInstance();
	Sprite** sprites; /* = (Sprite*)* sprites; */
	SpriteManager();
	~SpriteManager();
};

