#pragma once
#include "MovableObject.h"
#include "DelayTime.h"

#pragma region ENUMERATIONS
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
#pragma endregion


class Door :
	public MovableObject
{
public:
	static DOOR_ACTIVITY doorActivity;
	static DelayTime doorDelay;
	static Door* currentDoor; // dia chi cua canh cua dang xu li

	void onCollision(FBox* other, int nx, int ny);
	void onLastFrameAnimation();

	/* CONSTRUCTOR & DESTRUCTOR */
	Door();
	~Door();

};

