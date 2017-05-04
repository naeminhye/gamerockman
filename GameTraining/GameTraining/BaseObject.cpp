#include "BaseObject.h"



void BaseObject::setAction(int actionValue)
{
	if (action != actionValue)
	{
		this->action = actionValue;
		frameIndex = 0;
	}
}

void BaseObject::restoreLocation()
{
	x = oldRect.x;
	y = oldRect.y;
	width = oldRect.width;
	height = oldRect.height;
}

BaseObject::BaseObject() 
{
	sprite = 0;
	delay.tickPerFrame = 100;
	frameIndex = 0;
	action = 0;
	pauseAnimation = false;
	alive = true;
}


BaseObject::~BaseObject()
{
}

void BaseObject::update()
{
	if (!alive)
		return;
	if (sprite == 0)
		return;
	FBox::update();

	if (pauseAnimation)
		return;

	if (delay.atTime())
	{
		sprite->update(action, frameIndex);
		if (frameIndex == 0)
		{
			onLastFrameAnimation();
		}
	}
}

void BaseObject::onLastFrameAnimation()
{
}

void BaseObject::render()
{
	if (!alive)
		return;
	if (sprite == 0)
		return;
	float yRender;
	float xRender;

	D3DXMATRIX flipMatrix;
	MGMCamera::getInstance()->Transform(x, y, xRender, yRender);
	xRender = (int)xRender;
	yRender = (int)yRender;
	if (direction != sprite->img->direction)
	{
		int frameWidth = sprite->anims[action].frames[frameIndex].right - sprite->anims[action].frames[frameIndex].left;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2*(xRender + frameWidth/2 );
		
		MGMDirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
	sprite->render(xRender, yRender, action, frameIndex);
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		MGMDirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
}

void BaseObject::init()
{
}
