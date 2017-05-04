#pragma once
#include "FBox.h"
#include "Sprite.h"
#include "MGMGameTime.h"
#include"SpriteManager.h"
#include "MGMCamera.h"
#include"Collision.h"

class BaseObject : public FBox
{
public:


	bool pauseAnimation;
	FRectangle oldRect;
	Sprite* sprite;
	virtual void setAction(int actionValue);
	int action, frameIndex;
	MGMGameTime delay;
	Direction direction;

	int id;

	//phuc hoi vi tri cu
	virtual void restoreLocation();

	BaseObject();
	~BaseObject();
	virtual void update();
	virtual void onLastFrameAnimation();
	virtual void render();
	virtual void init();
};

