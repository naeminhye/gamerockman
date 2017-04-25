#pragma once
#include "Config.h"
#include "MGMTexture.h"
#include"FBox.h"
#include"ObjectsFilter.h"
#include "Stage.h"
class MGMCamera: public FBox
{
private:
	static MGMCamera* instance;
public:
	static MGMCamera* getInstance();
	void Transform(float x, float y, float& xRender, float& yRender);
	void update();
	ObjectsFilter objects;

	void onCollision(FBox * other, int nx, int ny);
	MGMCamera();
	~MGMCamera();
};

