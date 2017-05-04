#pragma once
#include "MovableObject.h"
#include "DelayTime.h"

enum DOOR_ACTION {
	DOOR_OPEN,
	DOOR_CLOSE
};

enum DOOR_ACTIVITY {
	DOOR_WAITING_TO_OPEN, // tu hieu
	DOOR_OPENING, //
	DOOR_CAMERA_CHANGING, //
	DOOR_CLOSING // 
};

class Door :
	public MovableObject
{
public:
	static DOOR_ACTIVITY doorActivity;
	static DelayTime doorDelay;
	static Door* currentDoor;

	void onCollision(FBox* other, int nx, int ny);
	void onLastFrameAnimation();
	Door();
	~Door();
};

