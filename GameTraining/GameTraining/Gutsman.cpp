#include "Gutsman.h"
#include "GutsmanRock.h"

extern int randomFrom(int numBegin, int numEnd);
extern float roundToInt(float num);
Gutsman* Gutsman::instance = 0;

void Gutsman::update()
{
	if (!alive)
		return;

	initDirectionFollowRockman();
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

	gm_waiting_delay.update();
	gm_attacking_delay.update();


	switch (gmActivity)
	{
	case GMA_GROUND:

		if (decision == GM_D_ATTACK)
		{
			updateAttack();
		}
		else
		{
			setAction(GM_WAITING);
			if (gm_waiting_delay.isTerminated())
			{
				setAction(GM_JUMPING);
				vy = GUTMAN_JUMP_VY;
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
			GutsmanRock::getInstance()->dx = direction * GM_ROCK_DX_VELOCITY; 
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
		vy = GUTMAN_JUMP_VY; 
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
		vy = GUTMAN_JUMP_VY; 
		gmActivity = GMA_JUMP;
	}
}

void Gutsman::render()
{
	if (sprite == 0)
		return;

	if (!alive)
		return;

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
		sprite->render(xRender, yRender, GM_EXPLOSE, 0);
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
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
			other->slideHandle();
			other->vy = 0;
		}

	}
	Enemy::onCollision(other, nx, ny);
}

void Gutsman::onIntersect(FBox * other)
{
	if (other->collisionType == CT_BULLET && other != GutsmanRock::getInstance() && !onInjury)
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
			setDeath();
		}
	}
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

void Gutsman::updateInjury()
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
	gm_waiting_delay.init(GM_WAITING_DELAY_TIME);
	gm_attacking_delay.init(GM_ATTACKING_DELAY_TIME);
	gm_waiting_delay.start();
	gmDecisionTable = new int[2];
	gmDecisionTable[GM_D_WAIT] = GM_WAIT_R;
	gmDecisionTable[GM_D_ATTACK] = GM_ATTACK_R;
	gmRandCount = GM_WAIT_R + GM_ATTACK_R;
	gmActivity = GMA_GROUND;
	delay.tickPerFrame = GM_ANIMATION_GAME_TIME; 
	instance = this;

	disappearTime.tickPerFrame = GM_DISAPPEAR_GAME_TIME; 
	isDisappear = false;
	isRecoil = false;
	injuryDelay.init(GM_INJURY_DELAY_TIME); 
	onInjury = false;
	healthPoint = GM_HEALTH_POINTS;
	attackDamage = GM_ATTACK_DAMAGE;
}


Gutsman::~Gutsman()
{
}
