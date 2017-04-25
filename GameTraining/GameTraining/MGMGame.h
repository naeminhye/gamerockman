#pragma once
#include"Config.h"
#include "Rockman.h"
#include "Collision.h"
#include"Map.h"
class MGMGame
{
	static MGMGame* instance;
public:
	static MGMGame* getInstance();
	int x,y;
	int dx,dy;
	Rockman man;
	int nObject;
	BaseObject* objects;
	MGMCamera* camera;
	MGMTexture* img;
	Map tilemap;

	void readFile(const char* objectsPath);
	

	void init();
	void update();
	void render();

	MGMGame(void);
	~MGMGame(void);
};

