#pragma once
#include"Config.h"
#include "Rockman.h"
#include "Collision.h"
#include"Map.h"
#include "Scene.h"

class MapScene : public Scene
{
	static MapScene* instance;
public:
	static MapScene* getInstance();
	//Scene* scene;
	int x,y;
	int dx,dy;
	Rockman man;
	int nObject;
	BaseObject* objects;
	MGMCamera* camera;
	MGMTexture* img;
	Map* curMap;
	void setCurMap(Map* map);

	void readFile(const char* objectsPath);
	

	void init();
	void update();
	void render();

	MapScene(void);
	~MapScene(void);
};

