#pragma once
#include"Sprite.h"

/* ENUMERATIONS */
enum SPRITE_INFO
{
	SPR_DEATH_HOLE = -8,
	SPR_BRIDGE = -7,
	SPR_SPIKE = -6,
	SPR_OUTERSPACE, // = - 5
	SPR_CUTTER, // = -4
	SPR_STONE, // = -3
	SPR_STAIR, // = -2
	// GROUND = -1
	SPR_ROCKMAN = 0, //= 0
	SPR_BLADER, // = 1
	SPR_BEAK, // = 2
	SPR_CUTTER_BULLET, //= 3
	SPR_FLEA, // = 4
	SPR_OCTOPUS, // = 5
	SPR_BULLET, // = 6
	SPR_BEAK_BULLET, // = 7
	SPR_SHELL, // = 8, FLYING SHELL
	SPR_EYE, // = 9 BIG EYE
	SPR_BOMBER, // = 10 SCREW BOMBER
	SPR_CUTMAN, // = 11
	SPR_DOOR, // = 12
	SPR_MET, // = 13
	SPR_TRUNDLE, // = 14
	SPR_PICKET, // = 15
	SPR_GUTSMAN, // = 16
	SPR_GUTSMAN_ROCK,
	SPR_GUTSMAN_BROKEN_ROCK,
	SPR_CUTMAN_SCISSORS, // 
	SPR_PICKET_BULLET,
	SPR_SELECT_MAP_FRAME,
	// TODO: them doi tuong

	SPR_ENEMY_DEATH, 
	SPR_ITEMS,
	SPR_COUNT //= so luong sprite
	
};



class SpriteManager
{
public:
	static SpriteManager* instance;
	Sprite** sprites; /* = (Sprite*)* sprites; */

	static SpriteManager* getInstance();
					  
	/* CONSTRUCTOR & DESTRUCTOR */
	SpriteManager();
	~SpriteManager();

};

