#include"Stairs.h"
#include "Rockman.h"
#include"KEY.h"
#include"Map.h"
#include "RockmanCutBullet.h"

Rockman * Rockman::instance = 0;
void Rockman::setHealth(int health)
{
	this->health = health;
}
Rockman * Rockman::getInstance()
{
	if (instance == 0)
		instance = new Rockman();
	return instance;
}

void Rockman::update()
{
	updateFlicker();
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
			setWidth(16);
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
		if (onAttack)
		{
			setAction(RM_RUN_SHOOT);
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
		if (onAttack)
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
			vy = RM_VY_JUMP;
		}
		setWidth(21); // TODO luu constant 
	}
	else
	{
		setAction(RM_JUMP);
		if (onAttack)
			setAction(RM_JUMP_SHOOT);
		setWidth(14); // TODO luu constant 
	}
	MovableObject::update();
}

void Rockman::render()
{
	if (isDisappear)
		return;
	if (sprite == 0)
		return;
	float yRender;
	float xRender;

	D3DXMATRIX flipMatrix;
	int frameWidth = sprite->anims[action].frames[frameIndex].right - sprite->anims[action].frames[frameIndex].left;
	MGMCamera::getInstance()->Transform(x, y, xRender, yRender);
	xRender = (int)xRender;
	yRender = (int)yRender;

	xRender -= (frameWidth - width) / 2;

	if (direction != sprite->img->direction)
	{
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
	if(disappearTime.atTime())
		isDisappear = !isDisappear;
}

void Rockman::setIsIntersectStair(bool isIntersectStair)
{
	this->isIntersectStair = isIntersectStair;
}

Rockman::Rockman()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_ROCKMAN];
	width = 20;// TODO luu constant
	height = 24;// TODO luu constant
	delay.tickPerFrame = 1000; // TODO luu constant
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
	disappearTime.tickPerFrame = 20;// TODO LUU CONSTANT
	isDisappear = false;
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
	this->onStair = onStair;
	if (onStair)
	{
		setWidth(16);
		vy = 0;
	}

}

void Rockman::updateStair()
{
	bool keyUp = KEY::getInstance()->isUpDown;
	bool keyDown = KEY::getInstance()->isDownDown;
	bool keyJumpPress = KEY::getInstance()->isJumpPress;
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
				setWidth(21);
				x = stairIntersect->right() - width;
				direction = Left;
			}
			else if (stairIntersect->id == STAIR_LEFT)
			{
				setWidth(21);
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

		if (stairIntersect != 0 && Rockman::getInstance()->top() > stairIntersect->top())
			Rockman::getInstance()->setAction(RM_END_STAIR);
		return;
	}
	if (keyDown)
	{
		BaseObject::update();
		dy = -STAIR_DY;
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
				bullet->dx = 3 * direction;
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
				int a = 50;//TODO them constant
				bullet->oldRect.x = x;
				bullet->oldRect.y = y;
				if (direction < 0)
				{
					bullet->oldRect.x = x - 2 * a;
				}
				bullet->dx = 3 * direction;
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
