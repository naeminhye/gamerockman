#include "ScrewBomber.h"
#include "BeakBullet.h"



void ScrewBomber::updateLocation()
{

}

void ScrewBomber::update()
{
	if (!alive)
		return;
	Enemy::update();
	if (abs(getXCenter() - Rockman::getInstance()->getXCenter()) < SCREW_BOMBER_SHOOTING_DISTANCE)
	{
		screwdelay.update();
		switch (screwactivity)
		{
		case SCREW_WAITING:
			if (screwdelay.isTerminated())
			{
				screwactivity = SCREW_SHOOTING;
				screwdelay.start(SCREW_BOMBER_DELAYTIME);
				setAction(SCREW_SHOOT);
				setHeight(16);
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
						if ((i != 0 || j != 0))
						{
							if (id == SCREW_TOP && j <= 0 || id == SCREW_BOTTOM && j >= 0)
							{
								BeakBullet* bullet = new BeakBullet();
								bullet->dx = SCREW_BOMBER_VELOCITY * i;
								bullet->dy = SCREW_BOMBER_VELOCITY * j; 
								bullet->x = getXCenter();
								bullet->y = getYCenter(); // TODO 
								if (i != 0 && j != 0)
								{
									bullet->dx *= sqrt(2) / 2;
									bullet->dy *= sqrt(2) / 2;
								}
							}

						}
				}
			}
			break;
		case SCREW_SHOOTING:
			if (screwdelay.isTerminated())
			{
				screwactivity = SCREW_WAITING;
				screwdelay.start(SCREW_BOMBER_DELAYTIME);
				setAction(SCREW_WAITING);
				setHeight(8);
			}
		default:
			break;
		}
	}
}

void ScrewBomber::render()
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
	if (id == SCREW_TOP)
	{
		int frameHeight = sprite->anims[action].frames[frameIndex].bottom - sprite->anims[action].frames[frameIndex].top;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._22 = -1;
		flipMatrix._42 = 2 * (yRender + frameHeight / 2);

		MGMDirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
	sprite->render(xRender, yRender, action, frameIndex);
	if (id == SCREW_TOP)
	{
		D3DXMatrixIdentity(&flipMatrix);
		MGMDirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
}

void ScrewBomber::setHeight(int height)
{
	if (id == SCREW_BOTTOM)
	{
		Enemy::setHeight(height);
	}
}

ScrewBomber::ScrewBomber()
{
	screwactivity = SCREW_WAITING;
	healthPoint = 3;
}


ScrewBomber::~ScrewBomber()
{
}
