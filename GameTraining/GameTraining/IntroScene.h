#pragma once
#include "Scene.h"
#include "MGMTexture.h"
class IntroScene :
	public Scene
{
public:
	MGMTexture* img;
	void init();
	void update();
	void render();

	/* CONSTRUCTOR & DESTRUCTOR */
	IntroScene();
	~IntroScene();\

};

