#pragma once
#include "FBox.h"
#include "Sprite.h"
#include "GameTime.h"
#include"SpriteManager.h"
#include "Camera.h"
#include"Collision.h"

class BaseObject : public FBox
{
public:
	bool pauseAnimation; // dung chuyen dong
	FRectangle oldRect; // vi tri truoc do cua doi tuong
	Sprite* sprite; 
	virtual void setAction(int actionValue); // chon hanh dong cho doi tuong
	int action, frameIndex;
	GameTime delay; // thoi gian de chuyen doi frame trong mot hanh dong
	Direction direction; // huong di cua doi tuong  
	int id; // id cua doi tuong, xem o SpriteManager

	/* CONSTRUCTOR & DESTRUCTOR */
	BaseObject();
	~BaseObject();

	virtual void update();
	virtual void render();
	virtual void init();
	virtual void onLastFrameAnimation(); // xu ly xu kien xay ra tai frame cuoi cua mot hanh dong
	virtual void restoreLocation(); //ham phuc hoi vi tri cu cua doi tuong 
};

