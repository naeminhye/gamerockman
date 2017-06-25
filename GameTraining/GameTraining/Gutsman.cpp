#include "Gutsman.h"

extern int randomFrom(int numBegin, int numEnd);

void Gutsman::update()
{
	gm_waiting_delay.update();
	//if (gm_waiting_delay.isTerminated())
	//{
	//	vy = 0.3; // TODO
	//	setAction(GM_JUMPING);
	//}

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


	Enemy::update();

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
			}
		}
	}
}

Gutsman::Gutsman()
{
	action = GM_WAITING;
	gm_waiting_delay.init(2000);
	gmDecisionTable = new int[2];
	gmDecisionTable[GM_D_WAIT] = GM_WAIT_R;
	gmDecisionTable[GM_D_ATTACK] = GM_ATTACK_R;
	gmRandCount = GM_WAIT_R + GM_ATTACK_R;
}


Gutsman::~Gutsman()
{
}
