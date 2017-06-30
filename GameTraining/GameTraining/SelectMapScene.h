#pragma once
#include "Scene.h"
#include "Texture.h"
#include "SelectMapFrame.h"

/* ENUMERATIONS */
enum MAP_TYPE {
	MT_CUTMAN,
	MT_GUTSMAN,

	MT_COUNT
};

class SelectMapScene :
	public Scene
{
public:

	static SelectMapScene* instance;

	Texture* img;
	SelectMapFrame* selectMapFrames;
	MAP_TYPE curSelect;
	
	void init();
	void update();
	void render();

	/* CONSTRUCTOR & DESTRUCTOR */
	SelectMapScene();
	~SelectMapScene();

};

