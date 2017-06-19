#include "Flickable.h"

extern int roundToInt(float num);

void Flickable::updateFlicker()
{
	if (disappearTime.atTime())
		isDisappear = !isDisappear;
}

void Flickable::render()
{
	float yRender;
	float xRender;
	D3DXMATRIX flipMatrix;
	int frameWidth = sprite->anims[action].frames[frameIndex].right - sprite->anims[action].frames[frameIndex].left;
	MGMCamera::getInstance()->Transform(x, y, xRender, yRender);
	xRender = roundToInt(xRender);
	yRender = roundToInt(yRender);

	xRender -= (frameWidth - width) / 2;
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xRender + frameWidth / 2);

		MGMDirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
	if (!isDisappear)
		sprite->render(xRender, yRender, action, frameIndex);
	if (injuryDelay.isOnTime() && isDisappear)
		sprite->render(xRender, yRender, flickerAction, 0);
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		MGMDirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
}

Flickable::Flickable()
{
	disappearTime.tickPerFrame = RM_DISAPPEAR_GAME_TIME; // TODO constant
	injuryDelay.init(RM_INJURY_DELAY_TIME);
	flickeringDelay.init(RM_FLICKER_DELAY_TIME);
}


Flickable::~Flickable()
{
}
