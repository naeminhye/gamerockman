#include "SelectMapFrame.h"



void SelectMapFrame::update()
{
	if (delay.atTime())
	{
		sprite->update(action, frameIndex);
	}
}

void SelectMapFrame::render()
{
	sprite->render(x, y, action, frameIndex);
}

SelectMapFrame::SelectMapFrame()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_SELECT_MAP_FRAME];
	delay.tickPerFrame = MAP_FRAMES_GAME_TIME;
	action = 0;
	frameIndex = 0;
}


SelectMapFrame::~SelectMapFrame()
{
}
