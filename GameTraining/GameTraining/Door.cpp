#include "Door.h"
#include "Map.h"

DOOR_ACTIVITY Door::doorActivity = DOOR_WAITING_TO_OPEN;
DelayTime Door::doorDelay;
Door* Door::currentDoor = 0;

void Door::onCollision(FBox * other, int nx, int ny)
{
	if (nx == -1)
	{
		currentDoor = this;
		Map::onStageChangeByDoor = true;
		doorActivity = DOOR_WAITING_TO_OPEN;
		Door::doorDelay.start(DOOR_DELAY_TIME);
		GameSound::getInstance()->play(SOUND_BOSS_GATE);

	}
	else
	{
		other->slideHandle();
	}
}

void Door::onLastFrameAnimation()
{
	if (doorActivity == DOOR_OPENING)
	{
		doorActivity = DOOR_CAMERA_CHANGING;
		pauseAnimation = true;
		frameIndex = sprite->anims[action].frameCount - 1;
	}
	else if (doorActivity == DOOR_CLOSING)
	{
		Map::onStageChangeByDoor = false;
		pauseAnimation = true;
		frameIndex = sprite->anims[action].frameCount - 1;
	}
}

Door::Door()
{
	collisionType = CT_DOOR;
	pauseAnimation = true;
}


Door::~Door()
{
}
