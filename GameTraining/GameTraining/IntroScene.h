#pragma once
#include "Scene.h"
#include "Texture.h"
class IntroScene :
	public Scene
{
public:
	Texture* img;
	void init();
	void update();
	void render();

	/* CONSTRUCTOR & DESTRUCTOR */
	IntroScene();
	~IntroScene();\

};

