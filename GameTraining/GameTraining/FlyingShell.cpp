#include "FlyingShell.h"
#include "BeakBullet.h"


void FlyingShell::update()
{
	flydelay.update();
	switch (flyactivity)
	{

	case FLY_RUNNING:
		dx = FLYING_SHELL_RUNNING_DY;
		if (flydelay.isTerminated())
		{
			flyactivity = FLY_STANDING;
			flydelay.start(FLYING_SHELL_DELAYTIME);
			setAction(FLY_OPEN);
			if (alive)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
						if (i != 0 || j != 0)
						{
							BeakBullet* bullet = new BeakBullet();
							bullet->dx = FLYING_SHELL_VELOCITY * i;
							bullet->dy = FLYING_SHELL_VELOCITY * j;
							bullet->x = getXCenter();
							bullet->y = getYCenter();
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
	case FLY_STANDING:
		dx = 0;
		if (flydelay.isTerminated())
		{
			flyactivity = FLY_RUNNING;
			flydelay.start(FLYING_SHELL_DELAYTIME);
			setAction(FLY_CLOSE);


		}
		break;
	default:
		break;
	}

}

void FlyingShell::onCollision(FBox * other, int nx, int ny)
{

}



FlyingShell::FlyingShell()
{
	direction = Left;
	flyactivity =  FLY_RUNNING;
	dx = FLYING_SHELL_RUNNING_DY;
	healthPoint = 1;
}


FlyingShell::~FlyingShell()
{
}
