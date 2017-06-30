#pragma once
#include"Config.h"
#include "Rockman.h"
#include "Collision.h"
#include"Map.h"
#include "Scene.h"
#include "SelectRockmanBoard.h"

class MapScene : public Scene
{
	static MapScene* instance;
public:
	
	int x,y;
	int dx,dy;
	Rockman man;
	int nObject;
	BaseObject* objects;
	Camera* camera;
	MGMTexture* img;
	Map* curMap;
	int selection;

	SelectRockmanBoard board;

	void readFile(const char* objectsPath);
	static MapScene* getInstance();
	void setCurMap(Map* map);
	

	void init();
	void update();
	void render();
	
	/* CONSTRUCTOR & DESTRUCTOR */
	MapScene(void);
	~MapScene(void);

	void changeRockman();
};

