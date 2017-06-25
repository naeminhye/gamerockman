#include"Stairs.h"
#include "Rockman.h"
#include"KEY.h"
#include"Map.h"
#include "RockmanCutBullet.h"
#include"RockmanDeath.h"
#include"Camera.h"
#include"Scene.h"

Rockman * Rockman::instance = 0;
void Rockman::setHealth(int health)
{
	if (onDeath)
		return;
	if (health <= 0)
	{
		setLife(life - 1);
		setAction(RM_DEATH);
		onDeath = true;
		//	alive = false;
		deathDelay.start();
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
				if (i != 0 || j != 0)
				{
					RockmanDeath* rmDead = new RockmanDeath();
					rmDead->dx = ROCKMAN_DEAD_VELOCITY * i;
					rmDead->dy = ROCKMAN_DEAD_VELOCITY * j;
					rmDead->x = getXCenter();
					rmDead->y = getYCenter();
					rmDead->width = sprite->getWidth(action, 2);
					rmDead->height = sprite->getHeight(action, 2);
					rmDead->setAction(action);
					if (i != 0 && j != 0)
					{
						rmDead->dx *= sqrt(2) / 2;
						rmDead->dy *= sqrt(2) / 2;
					}

				}
		}
	}
	this->health = health; 
	if (health > maxHealth)
		this->health = maxHealth;
}

void Rockman::updateDeath()
{
	dx = 0;
	dy = 0;
	switch (rm_death_activity)
	{
	case ON_DEATH:
		if (deathDelay.isTerminated())
		{
			RockmanDeath* rmDead = new RockmanDeath();
			rmDead->dx = ROCKMAN_DEAD_VELOCITY;
			rmDead->dy = 0;
			rmDead->x = getXCenter();
			rmDead->y = getYCenter();
			rmDead->width = sprite->getWidth(action, 2);
			rmDead->height = sprite->getHeight(action, 2);
			rmDead->setAction(action);

			rmDead = new RockmanDeath();
			rmDead->dx = 0;
			rmDead->dy = ROCKMAN_DEAD_VELOCITY;
			rmDead->x = getXCenter();
			rmDead->y = getYCenter();
			rmDead->width = sprite->getWidth(action, 2);
			rmDead->height = sprite->getHeight(action, 2);
			rmDead->setAction(action);

			rmDead = new RockmanDeath();
			rmDead->dx = -ROCKMAN_DEAD_VELOCITY;
			rmDead->dy = 0;
			rmDead->x = getXCenter();
			rmDead->y = getYCenter();
			rmDead->width = sprite->getWidth(action, 2);
			rmDead->height = sprite->getHeight(action, 2);
			rmDead->setAction(action);

			rmDead = new RockmanDeath();
			rmDead->dx = 0;
			rmDead->dy = -ROCKMAN_DEAD_VELOCITY;
			rmDead->x = getXCenter();
			rmDead->y = getYCenter();
			rmDead->width = sprite->getWidth(action, 2);
			rmDead->height = sprite->getHeight(action, 2);
			rmDead->setAction(action);
			rm_death_activity = DEATH_FINISH;
			deathDelay.start();
		}
		break;
	case DEATH_FINISH:
		// ve stage 1
		if (deathDelay.isTerminated())
		{
			Stage::curStage = Map::curMap->stages[Map::curMap->stageBegin];
			Camera::getInstance()->x = Map::curMap->cameraBeginX;
			Camera::getInstance()->y = Map::curMap->cameraBeginY;
			x = Map::curMap->rmBeginX;
			y = Map::curMap->rmBeginY;
			this->Rockman::Rockman();
			rm_type = RMT_NORMAL;
			pauseAnimation = true;
			ground = false;
			setAction(RM_TELEPORT);
			onTeleport = true;
			Camera::getInstance()->objects.clear();
			for (size_t i = 0; i < RockmanDeath::deads->Count; i++)
			{
				RockmanDeath::deads->at(i)->deleteDead();
				i--;
			}
		}
		break;
	default:
		break;
	}
	deathDelay.update();

}

void Rockman::setLife(int life)
{
	this->life = life;
	if (life == 0)
	{
		// game over
	}
}

Rockman * Rockman::getInstance()
{
	if (instance == 0)
		instance = new Rockman();
	return instance;
}

void Rockman::update()
{
	if (!alive)
		return;
	if (onDeath)
	{
		updateDeath();
		return;
	}
	updateInjury();

	if (ground) {
		isRecoil = false; 
		pauseAnimation = false;
	}
	if (isRecoil)
	{
		MovableObject::update();
		return;
	}

	updateRockmanType();

	if (onTeleport)
	{
		updateTeleport();
		return;
	}

	updateAttack();
	shootDelay.update();
	if (shootDelay.isTerminated())
	{
		onAttack = false;
	}

	if (onStair)
	{
		updateStair();
		isIntersectStair = false;
		stairIntersect = 0;
		if (onAttack)
		{
			setAction(RM_STAIR_SHOOT);
			setWidth(RM_STAIR_SHOOT_WIDTH);
		}
		return;
	}
	stairIntersect = 0;
	isIntersectStair = false;

	bool keyUp, keyDown, keyLeft, keyRight, keyAttackPress;
	bool keyJump, keyJumpPress;
	keyAttackPress = KEY::getInstance()->isAttackPress;
	keyLeft = KEY::getInstance()->isLeftDown;
	keyRight = KEY::getInstance()->isRightDown;
	bool keyMove = keyLeft || keyRight;
	keyJump = KEY::getInstance()->isJumpDown;
	keyJumpPress = KEY::getInstance()->isJumpPress;

	if (keyLeft)
	{
		direction = Left;
	}
	else if (keyRight)
	{
		direction = Right;
	}


	if (keyMove)
	{
		if (onAttack && ground && vx != 0)
		{
			setAction(RM_RUN_SHOOT);
			//	else
			//		setAction(RM_RUN_SHOOT);

		}
		else {
			vx = RM_V_RUN * direction;
			if (rm_action != RM_RUN)
				setAction(RM_PREPARE_RUN);
			else
				setAction(RM_RUN);
		}
	}
	else
	{
		if (onAttack && ground && (vx == 0))
		{
			setAction(RM_STAND_SHOOT);
		}
		else
		{
			vx = RM_VX_STAND;
			updateBlink();
		}

	}

	if (ground)
	{
		if (keyJumpPress)
		{
			GameSound::getInstance()->play(SOUND_BEAM);
			vy = RM_VY_JUMP;
		}
		setWidth(RM_GROUND_WIDTH);
	}
	else
	{
		setAction(RM_JUMP);
		if (onAttack)
			setAction(RM_JUMP_SHOOT);
		setWidth(RM_JUMP_WIDTH); 
	}
	MovableObject::update();
}

float roundToInt(float num)
{
	return (int)(num +0.5);
}

void Rockman::render()
{
	if (sprite == 0)
		return;

	if (onDeath)
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

	//int deltaX = 0;

	//if (direction == Right)
	//{
	//	deltaX = width - frameWidth + 1;
	//}

	//xRender += deltaX;

	

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
		sprite->render(xRender, yRender, RM_EXPLOSE, 0);
	if (direction != sprite->img->direction)
	{
		D3DXMatrixIdentity(&flipMatrix);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}
}

void Rockman::setWidth(int width)
{
	MovableObject::setWidth(16);
}


void Rockman::onLastFrameAnimation()
{
	if (rm_action == RM_PREPARE_RUN)
	{
		bool keyLeft = KEY::getInstance()->isLeftDown;
		bool keyRight = KEY::getInstance()->isRightDown;
		bool keyMove = keyLeft || keyRight;

		if (keyMove)
			setAction(RM_RUN);
		else
			setAction(RM_STAND);
	}
	if (onTeleport)
	{
		onTeleport = false;
		setHeight(sprite->getHeight(RM_STAND, 0));
		setAction(RM_JUMP);

	}
}

bool Rockman::isAttack()
{
	return (rm_action == RM_STAND_SHOOT) || (rm_action == RM_RUN_SHOOT || (rm_action == RM_STAIR_SHOOT));
}

void Rockman::updateTeleport()
{
	setHeight(sprite->getHeight(action, frameIndex));
	if (ground)
	{
		pauseAnimation = false;
	}
	BaseObject::update();
	MovableObject::updateMove();
}

void Rockman::updateRockmanType()
{
	bool keyQ, keyW;
	keyQ = KEY::getInstance()->isQDown;
	keyW = KEY::getInstance()->isWDown;

	if (keyQ)
	{
		rm_type = ROCKMAN_TYPE::RMT_NORMAL;
		this->action = rm_type* RM_ACTION_COUNT + rm_action;
	}
	else if (keyW)
	{
		rm_type = ROCKMAN_TYPE::RMT_CUTMAN;
		this->action = rm_type* RM_ACTION_COUNT + rm_action;
	}
}

void Rockman::updateFlicker()
{
	if (disappearTime.atTime())
		isDisappear = !isDisappear;
}

void Rockman::updateInjury()
{
	if (onInjury)
	{
		injuryDelay.update();
		flickeringDelay.update();
		if (injuryDelay.isOnTime())
		{
			setAction(RM_INJURE);
		}
		updateFlicker();
		if (flickeringDelay)
		{
			onInjury = false;
			isDisappear = false;
		}
	}
}

void Rockman::setIsIntersectStair(bool isIntersectStair)
{
	this->isIntersectStair = isIntersectStair;
}

Rockman::Rockman()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_ROCKMAN];
	width = RM_WIDTH;
	height = RM_HEIGHT;
	delay.tickPerFrame = RM_DELAY_GAME_TIME;
	setOnStair(false);
	rm_action = RM_STAND;
	rm_type = RMT_NORMAL;
	blinkActivity = BLINK_OPEN;
	blinkDelay.start(TIME_BLINK_OPEN);
	rmBulletDelay.init(RM_BULLET_WAITING_DELAYTIME);
	shootDelay.init(RM_SHOOTING_DELAYTIME);
	direction = Right;
	onAttack = false;
	collisionType = CT_ROCKMAN;
	
	disappearTime.tickPerFrame = RM_DISAPPEAR_GAME_TIME;
	isDisappear = false;
	isRecoil = false;
	injuryDelay.init(RM_INJURY_DELAY_TIME);
	flickeringDelay.init(RM_FLICKER_DELAY_TIME);
	onInjury = false;

	health = maxHealth = RM_MAX_HEALTH_POINT;
	onDeath = false;
	deathDelay.init(RM_DEATH_DELAYTIME); 
	pauseAnimation = true;
	rm_death_activity = ON_DEATH;
	life = RM_DEFAULT_LIFE;
}


Rockman::~Rockman()
{
}

void Rockman::onCollision(FBox * other, int nx, int ny)
{
	bool keyDown = KEY::getInstance()->isDownDown;
	if (onStair && other->collisionType == CT_GROUND && ny == 1 && isIntersectStair && keyDown)
		onStair = false;
	if (onStair)
		return;
	if (other->collisionType == CT_STAIR && ny == 1 && !keyDown)
	{
		vy = -0.1f;
		slideHandle();
		ground = true;
	}


	if (other->collisionType == CT_GROUND && ny == 1)
	{
		ground = true;
	}


	BaseObject::onCollision(other, nx, ny);
}

void Rockman::updateBlink()
{
	if (rm_action == RM_PREPARE_RUN)
		return;
	blinkDelay.update();
	switch (blinkActivity)
	{
	case BLINK_OPEN:
		setAction(RM_STAND);
		if (blinkDelay.isTerminated())
		{
			blinkActivity = BLINK_CLOSE;
			blinkDelay.start(TIME_BLINK_CLOSE);
		}
		return;
	case BLINK_CLOSE:
		setAction(RM_BLINK);
		if (blinkDelay.isTerminated())
		{
			blinkActivity = BLINK_OPEN;
			blinkDelay.start(TIME_BLINK_OPEN);
		}
		return;
	default:
		break;
	}
}

void Rockman::setOnStair(bool onStair)
{
	if (isRecoil)
		onStair=false;
	this->onStair = onStair;
	if (onStair)
	{
		//setWidth(16);
		vy = 0;
	}

}

void Rockman::updateStair()
{
	bool keyUp = KEY::getInstance()->isUpDown;
	bool keyDown = KEY::getInstance()->isDownDown;
	bool keyLeft = KEY::getInstance()->isLeftDown;
	bool keyRight = KEY::getInstance()->isRightDown;
	bool keyJumpPress = KEY::getInstance()->isJumpPress;
	
	if (keyLeft)
		direction = Left;
	if (keyRight)
		direction = Right;

	ground = false; //***
	dy = 0;
	Rockman::getInstance()->setAction(RM_STAIR);

	if (stairIntersect == 0)
	{
		setOnStair(false);
		return;
	}

	if (!isIntersectStair && keyUp)
	{
		if (stairIntersect != 0)
		{
			y = stairIntersect->y + height;
			ground = true;
			//	vy = -0.1f;
			if (stairIntersect->id == STAIR_RIGHT)
			{
				//setWidth(21);
				x = stairIntersect->right() - width;
				direction = Left;
			}
			else if (stairIntersect->id == STAIR_LEFT)
			{
				//setWidth(21);
				x = stairIntersect->left();
				direction = Right;
			}
			setOnStair(false);
			return;
		}
	}


	if (keyUp)
	{
		BaseObject::update();
		dy = STAIR_DY;
		if (stairIntersect)
		{
			x = stairIntersect->x;
		}
		if (stairIntersect != 0 && Rockman::getInstance()->top() > stairIntersect->top())
			Rockman::getInstance()->setAction(RM_END_STAIR);
		return;
	}
	if (keyDown)
	{
		BaseObject::update();
		dy = -STAIR_DY;
		if (stairIntersect)
		{
			x = stairIntersect->x;
		}
		if (stairIntersect != 0 && Rockman::getInstance()->top() > stairIntersect->top())
			Rockman::getInstance()->setAction(RM_END_STAIR);
		return;
	}
	if (keyJumpPress)
	{
		setOnStair(false);
	}
}

void Rockman::setAction(int actionValue)
{
	if (injuryDelay.isOnTime() && actionValue != RM_INJURE)
	{
		return;
	}

	//if (onAttack && actionValue!= RM_STAND_SHOOT&& actionValue != RM_RUN_SHOOT)
	//	return;
	if (actionValue > RM_ACTION_COUNT)
	{
		MovableObject::setAction(actionValue);
		return;
	}
	if (rm_action != actionValue)
	{
		rm_action = (ROCKMAN_ACTION)actionValue;
		this->action = rm_type* RM_ACTION_COUNT + actionValue;
		frameIndex = 0;

	}
}

bool Rockman::checkChangeNextStage(List<Stage*>* stages)
{
	if (Stage::curStage->index + 1 == stages->Count)
		return false;
	auto nextStage = stages->at(Stage::curStage->index + 1);

	if (Collision::AABBCheck(this, nextStage) && onStair)
		return true;

	return false;
}

bool Rockman::checkChangePrevStage(List<Stage*>* stages)
{
	if (Stage::curStage->index == 0)
		return false;
	auto prevStage = stages->at(Stage::curStage->index - 1);

	if (Collision::AABBCheck(this, prevStage))
		return true;

	return false;
}

void Rockman::updateAttack()
{
	bool keyAttackPress, keyLeft, keyRight;
	keyLeft = KEY::getInstance()->isLeftDown;
	keyRight = KEY::getInstance()->isRightDown;
	bool keyMove = keyLeft || keyRight;
	keyAttackPress = KEY::getInstance()->isAttackPress;
	if (keyAttackPress)
	{
		onAttack = true;
		//if(!shootDelay.isOnTime())
		shootDelay.start();

		switch (rm_type)
		{
		case RMT_NORMAL:
			if (!rmBulletDelay.isOnTime() && RockmanBullet::bullets->Count < 3)
			{
				RockmanBullet* bullet = new RockmanBullet();
				bullet->dx = 5 * direction; // TODO
				bullet->dy = 0;
				bullet->x = x;
				if (direction == Right)
					bullet->x += width;
				bullet->y = y - 8;
				rmBulletDelay.start();
			}
			break;
		case RMT_CUTMAN:
			if (!rmBulletDelay.isOnTime() && RockmanBullet::bullets->Count < 1)
			{
				RockmanBullet* bullet = new RockmanCutBullet();
				bullet->direction = direction;
				int a = RM_CUT_BULLET_A;
				bullet->oldRect.x = x;
				bullet->oldRect.y = y;
				if (direction < 0)
				{
					bullet->oldRect.x = x - 2 * a; // TODO
				}
				bullet->dx = 3 * direction; // TODO
				bullet->dy = 0;
				bullet->x = x;

				if (direction == Right)
					bullet->x += width;
				bullet->y = y - 8;
				rmBulletDelay.start();
			}

			break;
		case RMT_GUSTMAN:
			break;
		default:
			break;
		}

	}
	rmBulletDelay.update();
}
