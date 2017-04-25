#include"Stairs.h"
#include "Rockman.h"
#include"KEY.h"
#include"Map.h"

Rockman * Rockman::instance = 0;
Rockman * Rockman::getInstance()
{
	if (instance == 0)
		instance = new Rockman();
	return instance;
}

void Rockman::update()
{
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
		setWidth(21);
	}
	else
	{
		setAction(RM_JUMP);
		setWidth(14);
	}
	MovableObject::update();
}

void Rockman::render()
{
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

void Rockman::setWidth(int width)
{
	if (direction == Right)
	{
		x += this->width - width;
	}

	this->width = width;
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

}

bool Rockman::isAttack()
{
	return (rm_action == RM_STAND_SHOOT) || (rm_action == RM_RUN_SHOOT);
}

void Rockman::setIsIntersectStair(bool isIntersectStair)
{
	this->isIntersectStair = isIntersectStair;
}

Rockman::Rockman()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_ROCKMAN];
	delay.tickPerFrame = 1000;
	setOnStair(false);
	rm_action = RM_STAND;
	rm_type = RMT_NORMAL;
	blinkActivity = BLINK_OPEN;
	blinkDelay.start(TIME_BLINK_OPEN);
	rmBulletDelay.init(RM_BULLET_WAITING_DELAYTIME);
	shootDelay.init(RM_SHOOTING_DELAYTIME);
	direction = Right;
	onAttack = false;
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
		Collision::PreventMoving(this, other);
		ground = true;
	}
	MovableObject::onCollision(other, nx, ny);
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
	if(onStair)
		setWidth(16);

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
			vy = -0.1f;
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
		if(!rmBulletDelay.isOnTime() && RockmanBullet::bullets->Count < 3)
		{
			RockmanBullet* bullet = new RockmanBullet();
			bullet->dx = 3*direction;
			bullet->dy = 0;
			bullet->x = x;
			if (direction == Right)
				bullet->x += width;

			bullet->y = y - 8;
			rmBulletDelay.start();
		}
	}
	rmBulletDelay.update();
}
