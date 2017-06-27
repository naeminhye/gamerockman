#include "Cutman.h"
#include "CutmanScissors.h"
#include "KEY.h"
#include "HealthSprite.h"

extern int time;
extern int randomFrom(int numBegin, int numEnd);
extern float roundToInt(float num);

void Cutman::setType(CUTMAN_TYPE cutmanType)
{
	this->cutmanType = cutmanType;
	if (action < CM_SHOOTING)
	{
		action = cutmanType*CM_ACTION_COUNT + cutmanAction;
	}

}

bool Cutman::checkNearRockman()
{
	float delta = CM_DISTANCE_TO_ROCKMAN; // TODO: luu constant
	return (abs(getXCenter() - Rockman::getInstance()->getXCenter()) < delta);
}

void Cutman::selectAttack()
{
	while (true)
	{
		int r, sum;
		r = randomFrom(0, randAttackCount - 1);
		sum = 0;

		for (int i = 0; i < CMRA_COUNT; i++)
		{
			sum += cmAttackTable[i];
			if (sum > r)
			{
				if (i != attackSelection && !(i == CM_ATTACKING_RANDOM_ACTIVITY::CMRA_JUMP_SHORT) ||
					(i == CM_ATTACKING_RANDOM_ACTIVITY::CMRA_JUMP_LONG))
				{
					if ((i == CM_ATTACKING_RANDOM_ACTIVITY::CMRA_JUMP_SHORT) ||
						(i == CM_ATTACKING_RANDOM_ACTIVITY::CMRA_JUMP_LONG)
						&& !checkNearRockman())
					{
						break;
					}
					else
					{
						attackSelection = (CM_ATTACKING_RANDOM_ACTIVITY)i;
						return;
					}
				}
				else
				{
					break;
				}
			}
		}
	}


}

void Cutman::selectNonAttack()
{
	while (true)
	{
		int r, sum;
		r = randomFrom(0, randNonAttackCount - 1);
		sum = 0;

		for (int i = 0; i < CMRA_COUNT; i++)
		{
			sum += cmNonAttackTable[i];
			if (sum > r)
			{
				if (i != nonAttackSelection && !((i == CM_NONATTACKING_RANDOM_ACTIVITY::CMNRA_JUMP_SHORT) ||
					(i == CM_NONATTACKING_RANDOM_ACTIVITY::CMNRA_JUMP_LONG)))
				{
					if ((i == CM_NONATTACKING_RANDOM_ACTIVITY::CMNRA_JUMP_SHORT) ||
						(i == CM_NONATTACKING_RANDOM_ACTIVITY::CMNRA_JUMP_LONG)
						&& !checkNearRockman())
					{
						break;
					}
					else
					{
						nonAttackSelection = (CM_NONATTACKING_RANDOM_ACTIVITY)i;
						return;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
}

void Cutman::onLastFrameAnimation()
{
	if (cutmanType == CM_NON_ATTACKING && nonAttackSelection == CMNRA_SHOOT)
	{
		canSelect = true;//restore from shoot
		CutmanScissors::getInstance()->alive = true;
		CutmanScissors::getInstance()->scissorsActivity = SCISSORS_ATTACK; // TODO doi ten
		CutmanScissors::getInstance()->x = x;
		CutmanScissors::getInstance()->y = y;
		CutmanScissors::getInstance()->dx = 2 * direction; // TODO Constant
		if (abs(CutmanScissors::getInstance()->x - Rockman::getInstance()->x) != 0)
		{
			CutmanScissors::getInstance()->dy = CutmanScissors::getInstance()->dx * (CutmanScissors::getInstance()->y - Rockman::getInstance()->y) / (CutmanScissors::getInstance()->x - Rockman::getInstance()->x);
		}
		else
		{
			CutmanScissors::getInstance()->dy = 0;
		}
		setType(CM_ATTACKING);
	}
}

void Cutman::onCollision(FBox * other, int nx, int ny)
{
	if (ny == 1 && other->collisionType == CT_GROUND)
	{
		if ((cutmanType == CM_NON_ATTACKING && (nonAttackSelection == CMNRA_JUMP_SHORT || nonAttackSelection == CMNRA_JUMP_LONG))
			|| (cutmanType == CM_ATTACKING && (attackSelection == CMRA_JUMP_SHORT || attackSelection == CMRA_JUMP_LONG)))
		{
			canSelect = true;//restore from jump
		}
	}
	if (nx != 0 && cutmanAction == CM_RUNNING)
	{
		canSelect = true;
	}
	Enemy::onCollision(other, nx, ny);
}

void Cutman::onIntersect(FBox * other)
{
	if (other->collisionType == CT_BULLET && other != CutmanScissors::instance && !onInjury)
	{
		int nx; //

		if (other->getXCenter() > getXCenter())
		{
			nx = -1;
		}
		else
			nx = 1;

		if (!injuryDelay.isOnTime())
		{
			direction = (Direction)(-nx);
			dx = nx; // TODO
			ground = false;
			isRecoil = true;
			onInjury = true;
			injuryDelay.start();
		}

		setHealthPoint(healthPoint - 1);
		if (healthPoint == 0)
		{
			//setDeath();
		}
	}
	else
	{

		if (other == Rockman::getInstance() && !Rockman::getInstance()->onInjury)
		{
			int nx; //

			if (getXCenter() > Rockman::getInstance()->getXCenter())
			{
				nx = -1;
			}
			else
				nx = 1;

			Rockman::getInstance()->direction = (Direction)(-nx);
			Rockman::getInstance()->vx = nx * RM_VX_RECOIL;
			//	Rockman::getInstance()->vx = 0; 
			Rockman::getInstance()->vy = RM_VY_RECOIL;
			Rockman::getInstance()->onStair = false;
			Rockman::getInstance()->ground = false;
			Rockman::getInstance()->isRecoil = true;
			Rockman::getInstance()->setIsIntersectStair(false);
			Rockman::getInstance()->setHealth(Rockman::getInstance()->health - attackDamage);
			Rockman::getInstance()->onInjury = true;
			Rockman::getInstance()->flickeringDelay.start();
			Rockman::getInstance()->injuryDelay.start();
			KEY::getInstance()->isUpDown = false;
			KEY::getInstance()->isDownDown = false;
		}
	}
}

void Cutman::updateLocation()
{
	Enemy::updateLocation();
}

void Cutman::updateMove()
{
	vy += ay*time;
	dy = vy*time;
}

void Cutman::updateInjury()
{
	if (onInjury)
	{
		injuryDelay.update();
		if (injuryDelay.isTerminated())
		{
			onInjury = false;
			isDisappear = false;
		}
		if (disappearTime.atTime())
			isDisappear = !isDisappear;
	}
	else
	{
		isDisappear = false;
		dx = 0;
	}
}

void Cutman::update()
{
	if (!alive)
		return;

	setHeight(sprite->getHeight(action, frameIndex));
	updateInjury();
	if (ground) {
		isRecoil = false;
	}
	if (isRecoil)
	{
		MovableObject::update();
		return;
	}
	switch (cutmanType)
	{
	case CM_NON_ATTACKING:
		updateNonAttacking();
		break;
	case CM_ATTACKING:
		updateAttacking();
		break;
	default:
		break;
	}
	Enemy::update();
}

void Cutman::render()
{
	if (sprite == 0)
		return;

	if (!alive)
		return;

	HealthSprite::getInstance()->render(30, 80, healthPoint, maxHealth); // TODO


	float yRender;
	float xRender;
	D3DXMATRIX flipMatrix;
	int frameWidth = sprite->anims[action].frames[frameIndex].right - sprite->anims[action].frames[frameIndex].left;
	Camera::getInstance()->Transform(x, y, xRender, yRender);
	xRender = roundToInt(xRender);
	yRender = roundToInt(yRender);

	xRender -= (frameWidth - width) / 2;
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xRender + frameWidth / 2);

		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
	if (!isDisappear)
		sprite->render(xRender, yRender, action, frameIndex);
	if (injuryDelay.isOnTime() && isDisappear)
		sprite->render(xRender, yRender, CM_EXPLOSE, 0);
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
}

void Cutman::updateNonAttacking()
{
	if (canSelect)
	{
		selectNonAttack();
		canSelect = false;
		initDirectionFollowRockman();
		switch (nonAttackSelection)
		{
		case CMNRA_WAIT:
			setAction(CM_WAITING);
			dx = 0;
			cutmanDelay.start(CM_WAITING_DELAY_TIME);
			break;
		case CMNRA_SHOOT:
			dx = 0;
			setAction(CM_SHOOTING);

			break;
		case CMNRA_RUN:
			setAction(CM_RUNNING);

			cutmanDelay.start(CM_RUNNING_DELAY_TIME);
			break;
		case CMNRA_JUMP_SHORT:
			setAction(CM_JUMPING);

			vy = CUTMAN_JUMP_VY; 
			break;
		case CMNRA_JUMP_LONG:
			setAction(CM_JUMPING);
			vy = CUTMAN_JUMP_VY; 
			break;
		default:
			break;
		}

	}

	switch (nonAttackSelection)
	{
	case CMNRA_WAIT:
		if (cutmanDelay.isTerminated())
		{
			canSelect = true; //restore from wait
		}
		break;
	case CMNRA_SHOOT:
		break;
	case CMNRA_RUN:
		dx = direction * CM_SHORT_JUMP_VELOCITY;
		if (cutmanDelay.isTerminated())
		{
			canSelect = true; //restore from run
		}
		break;
	case CMNRA_JUMP_SHORT:
		dx = direction * CM_SHORT_JUMP_VELOCITY;
		break;
	case CMNRA_JUMP_LONG:
		dx = direction * CM_LONG_JUMP_VELOCITY;
		break;
	default:
		break;
	}

	cutmanDelay.update();
}

void Cutman::updateAttacking()
{
	if (canSelect)
	{
		selectAttack();
		canSelect = false;
		initDirectionFollowRockman();
		switch (attackSelection)
		{
		case CMRA_WAIT:
			setAction(CM_WAITING);
			dx = 0;
			cutmanDelay.start(CM_WAITING_DELAY_TIME);
			break;
		case CMRA_RUN:
			setAction(CM_RUNNING);
			cutmanDelay.start(CM_RUNNING_DELAY_TIME);
			break;
		case CMRA_JUMP_SHORT:
			setAction(CM_JUMPING);
			vy = CUTMAN_JUMP_VY; 
			break;
		case CMRA_JUMP_LONG:
			setAction(CM_JUMPING);
			vy = CUTMAN_JUMP_VY;
			break;
		default:
			break;
		}

	}

	switch (attackSelection)
	{
	case CMRA_WAIT:
		if (cutmanDelay.isTerminated())
		{
			canSelect = true; //restore from wait
		}
		break;
	case CMRA_RUN:
		dx = direction * CM_SHORT_JUMP_VELOCITY;
		if (cutmanDelay.isTerminated())
		{
			canSelect = true; //restore from run
		}
		break;
	case CMRA_JUMP_SHORT:
		dx = direction * CM_SHORT_JUMP_VELOCITY;
		break;
	case CMRA_JUMP_LONG:
		dx = direction * CM_LONG_JUMP_VELOCITY;
		break;
	default:
		break;
	}

	cutmanDelay.update();
}

void Cutman::setAction(int actionValue)
{
	if (actionValue != cutmanAction)
	{
		action = cutmanType*CM_ACTION_COUNT + actionValue;
		cutmanAction = (CUTMAN_ACTION)actionValue;
		frameIndex = 0;
	}
}

Cutman::Cutman()
{
	cmAttackTable = new int[CM_ATTACKING_RANDOM_ACTIVITY::CMRA_COUNT];
	cmAttackTable[CMRA_WAIT] = CM_WAIT_R;
	cmAttackTable[CMRA_RUN] = CM_RUN_R;
	cmAttackTable[CMRA_JUMP_SHORT] = CM_JUMP_SHORT_R;
	cmAttackTable[CMRA_JUMP_LONG] = CM_JUMP_LONG_R;

	randAttackCount = CM_WAIT_R + CM_RUN_R + CM_JUMP_SHORT_R + CM_JUMP_LONG_R;


	cmNonAttackTable = new int[CM_NONATTACKING_RANDOM_ACTIVITY::CMNRA_COUNT];
	cmNonAttackTable[CMNRA_WAIT] = CM_NON_WAIT_R;
	cmNonAttackTable[CMNRA_SHOOT] = CM_NON_SHOOT_R;
	cmNonAttackTable[CMNRA_RUN] = CM_NON_RUN_R;
	cmNonAttackTable[CMNRA_JUMP_SHORT] = CM_NON_JUMP_SHORT_R;
	cmNonAttackTable[CMNRA_JUMP_LONG] = CM_NON_JUMP_LONG_R;
	randNonAttackCount = CM_NON_WAIT_R + CM_NON_SHOOT_R + CM_NON_RUN_R + CM_NON_JUMP_SHORT_R + CM_NON_JUMP_LONG_R;

	cutmanType = CM_NON_ATTACKING;
	setAction(CM_WAITING);

	CutmanScissors::getInstance()->cutman = this;

	canSelect = true;
	cutmanDelay.init(CM_STARTING_DELAY_TIME);//TODO luu constant

	
	disappearTime.tickPerFrame = CM_DISAPPEAR_GAME_TIME; //TODO 
	isDisappear = false;
	isRecoil = false;
	injuryDelay.init(CM_INJURY_DELAY_TIME); //TODO 
	onInjury = false;

	healthPoint = CM_HEALTH_POINTS;
	attackDamage = CM_ATTACK_DAMAGE;//TODO
}


Cutman::~Cutman()
{
}
