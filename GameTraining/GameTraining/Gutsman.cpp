#include "Gutsman.h"
#include "GutsmanRock.h"

extern int randomFrom(int numBegin, int numEnd);
Gutsman* Gutsman::instance = 0;

void Gutsman::update()
{
	if (!alive)
		return;
	initDirectionFollowRockman();
	setHeight(sprite->getHeight(action, frameIndex));

	gm_waiting_delay.update();
	gm_attacking_delay.update();


	switch (gmActivity)
	{
	case GMA_GROUND:

		if (decision == GM_D_ATTACK)
		{
			//gmActivity = GMA_GROUND;

			updateAttack();

			//setAction(GM_JUMPING);
			//vy = 0.3; // TODO
			//gmActivity = GMA_JUMP;
		}
		else
		{
			//vy = 0;
			setAction(GM_WAITING);
			if (gm_waiting_delay.isTerminated())
			{
				setAction(GM_JUMPING);
				vy = 0.3; // TODO
				gmActivity = GMA_JUMP;
			}
		}

		break;
	case GMA_JUMP:
		if (ground)
		{
			gmSelectAttack();
			gmActivity = GMA_GROUND;
			if (decision == GM_D_WAIT)
			{
				gm_waiting_delay.start();
			}
			else
			{
				gm_attacking_delay.start();
				gmAttackActivity = GM_ATTACK_RAISING_HAND;
			}
		}
		break;
	default:
		break;
	}

	Enemy::update();
	//if (gmCanSelect)
	//{
	//	gmSelectAttack();
	//	gmCanSelect = false;
	////	if (ground)
	////	{
	////		// chom decision , de ham random o dayyyyyy
	////		//gmSelectAttack();
	////		gm_waiting_delay.start();
	////	}
	//}
	//else
	//{
	//	if (decision == GM_D_ATTACK)
	//	{

	//	}
	//}


}

void Gutsman::updateAttack()
{
	switch (gmAttackActivity)
	{
	case GM_ATTACK_RAISING_HAND:
		setAction(GM_HOLDING_ROCK);
		pauseAnimation = true;
		frameIndex = 0;
		if (gm_attacking_delay.isOnTime())
		{
			GutsmanRock::getInstance()->gmrActivity = GMR_FALLING;
			GutsmanRock::getInstance()->x = x;
			GutsmanRock::getInstance()->y = Stage::curStage->top() + GutsmanRock::getInstance()->height;
			GutsmanRock::getInstance()->alive = true;
			GutsmanRock::getInstance()->vy = 0;
			gmAttackActivity = GM_ATTACK_ROCK_FALLING;
		}
		break;
	case GM_ATTACK_ROCK_FALLING:

		break;
	case GM_ATTACK_HOLDING_ROCK:
		if (gm_attacking_delay.isTerminated())
		{
			setAction(GM_THROWING_ROCK);
			GutsmanRock::getInstance()->gmrActivity = GMR_THROWING;
			GutsmanRock::getInstance()->gmrThrowActivity = GMR_THROW_NORMAL;
			GutsmanRock::getInstance()->dx = direction * 7; // TODO
			GutsmanRock::getInstance()->dy = GutsmanRock::getInstance()->dx * (GutsmanRock::getInstance()->y - Rockman::getInstance()->y) / (GutsmanRock::getInstance()->x - Rockman::getInstance()->x);
			gmAttackActivity = GM_ATTACK_THROWING_ROCK;
			gm_attacking_delay.start(500);// TODO
		}
		break;
	case GM_ATTACK_THROWING_ROCK:
		if (gm_attacking_delay.isTerminated())
		{
			gmAttackActivity = GM_ATTACK_FINISH;
		}
		break;
	case GM_ATTACK_FINISH:
		setAction(GM_JUMPING);
		vy = 0.3; // TODO
		gmActivity = GMA_JUMP;
		break;
	default:
		break;
	}
}

void Gutsman::onLastFrameAnimation()
{
	if (action == GM_HOLDING_ROCK)
	{
		setAction(GM_THROWING_ROCK);
	}
	else if (action == GM_THROWING_ROCK)
	{
		setAction(GM_JUMPING);
		vy = 0.3; // TODO
		gmActivity = GMA_JUMP;
	}
}

void Gutsman::onCollision(FBox * other, int nx, int ny)
{
	if (other == GutsmanRock::getInstance() && ny == 1)
	{
		if (GM_ATTACK_ROCK_FALLING == gmAttackActivity)
		{
			gmAttackActivity = GM_ATTACK_HOLDING_ROCK;
			gm_attacking_delay.start(500);//TODO
		}

		if (GutsmanRock::getInstance()->gmrActivity == GMR_FALLING)
		{
			//setAction(GM_THROWING_ROCK);
			other->slideHandle();
			//other->dy = 0;
			other->vy = 0;
		}

		

	}
	Enemy::onCollision(other, nx, ny);
}

void Gutsman::gmSelectAttack()
{
	while (true)
	{
		int r = randomFrom(0, gmRandCount);

		int sum = 0;

		for (int i = 0; i < 2; i++)
		{
			sum += gmDecisionTable[i];
			if (sum > r)
			{
				decision = (GM_DECISION)i;
				return;
			}
		}
	}
}

void Gutsman::updateLocation()
{
	if (isCollision && !isChangeDelta)
	{
		if (abs(dx) > abs(dy))
			dy = 0;
		else
			dx = 0;
	}
	x = (x + dx);
	y = (y + dy);
}

Gutsman::Gutsman()
{
	action = GM_WAITING;
	gm_waiting_delay.init(2000);// TODO
	gm_attacking_delay.init(1500);// TODO
	gm_waiting_delay.start();
	gmDecisionTable = new int[2];
	gmDecisionTable[GM_D_WAIT] = GM_WAIT_R;
	gmDecisionTable[GM_D_ATTACK] = GM_ATTACK_R;
	gmRandCount = GM_WAIT_R + GM_ATTACK_R;
	gmActivity = GMA_GROUND;
	delay.tickPerFrame = 200; // TODO
	instance = this;
}


Gutsman::~Gutsman()
{
}
