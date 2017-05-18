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
	delay.tickPerFrame = 100;//TODO luu constant
	action = 0;
	frameIndex = 0;
}


SelectMapFrame::~SelectMapFrame()
{
}
