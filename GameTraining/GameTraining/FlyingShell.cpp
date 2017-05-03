#include "FlyingShell.h"
#include "BeakBullet.h"


void FlyingShell::update()
{
	flydelay.update();
	switch (flyactivity)
	{
		
	case FLY_RUNNING:
		dx = -1;
		if (flydelay.isTerminated())
		{
			flyactivity = FLY_STANDING;
			flydelay.start(1000);
			setAction(FLY_OPEN);
			
			for (int i = -1; i <= 1; i++)
			{
				for(int j=-1;j<=1;j++)
					if (i != 0 || j != 0)
					{
						BeakBullet* bullet = new BeakBullet();
						bullet->dx = 3*i;
						bullet->dy = 3 * j; // TODO
						bullet->x = xCenter();
						bullet->y = yCenter();
						if (i != 0 && j != 0)
						{
							bullet->dx *= sqrt(2) / 2;
							bullet->dy *= sqrt(2) / 2;
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
			flydelay.start(1000);
			setAction(FLY_CLOSE);
			

		}
		break;
	/*case BEAK_SHOOTING:
		if (updateAttack())
		{
			beakActivity = BEAK_CLOSING;
			pauseAnimation = false;
			setAction(BEAK_CLOSE);
		}
		break;*/
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
	dx = -1;
}


FlyingShell::~FlyingShell()
{
}
