#include "RockmanDeath.h"


List<RockmanDeath*>* RockmanDeath::deads = new List<RockmanDeath*>();


RockmanDeath::RockmanDeath()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_ROCKMAN];
	deads->_Add(this);
	delay.tickPerFrame = 50;
}




RockmanDeath::~RockmanDeath()
{
}

void RockmanDeath::updateLocation()
{
	x += dx;
	y += dy;
}

void RockmanDeath::update()
{
	BaseObject::update();
}

void RockmanDeath::render()
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
	xRender -= (sprite->getWidth(action, frameIndex) - width) / 2;
	yRender -= (sprite->getHeight(action, frameIndex) - height) / 2;
	if (direction != sprite->img->direction)
	{
		int frameWidth = sprite->anims[action].frames[frameIndex].right - sprite->anims[action].frames[frameIndex].left;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xRender + frameWidth / 2);

		MGMDirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
	sprite->render(xRender, yRender, action, frameIndex);
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		MGMDirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
}

void RockmanDeath::deleteDead()
{
	deads->_Remove(this);
	delete this;
}
