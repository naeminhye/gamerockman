#include "CutmanScissors.h"
#include"Cutman.h"
extern float roundToInt(float num);
CutmanScissors * CutmanScissors::instance = 0;

void CutmanScissors::slideHandle()
{
}

void CutmanScissors::updateLocation()
{
	x = roundToInt(x + dx);
	y = roundToInt(y + dy);
}

CutmanScissors * CutmanScissors::getInstance()
{
	if (instance == 0)
		instance = new CutmanScissors();
	return instance;
}


void CutmanScissors::update()
{
	if (!alive)
		return;
	dx = direction * CM_SCISSORS_DX_VELOCITY;
	int delta = CM_SCISSORS_DISTANCE_TO_ROCKMAN; // TODO luu constant
	BaseObject::update();
	switch (scissorsActivity)
	{
	case SCISSORS_ATTACK:
		if ((x < Stage::curStage->left() + delta && dx < 0) ||
			(x > Stage::curStage->right() - delta && dx > 0))
		{
			direction = (Direction)(-direction);
			scissorsActivity = SCISSORS_RETURN;
		}

		if ((y > Stage::curStage->top() + delta ) ||
			(y < Stage::curStage->bottom() - delta ))
		{
			direction = (Direction)(-direction);
			scissorsActivity = SCISSORS_RETURN;
		}
		break;
	case SCISSORS_RETURN:
		if (alive && Collision::AABBCheck(this, cutman))
		{
			alive = false;
			Cutman* cutman1 = ((Cutman*)cutman);
			cutman1->setType( CM_NON_ATTACKING);
			cutman1->canSelect = true;
			return;
		}
		if ( abs( x - cutman->x) !=0 )
		{
			dy = dx * (y - cutman->y) / (x - cutman->x);
		}
		else
		{
			alive = false;
			Cutman* cutman1 = ((Cutman*)cutman);
			cutman1->setType(CM_NON_ATTACKING);
			cutman1->canSelect = true;
			return;
		}
		
		break;
	default:
		break;
	}
}

void CutmanScissors::onCollision(FBox * other, int nx, int ny)
{
	//if (other->collisionType == CT_GROUND && scissorsActivity != SCISSORS_RETURN)
	//{
	//	direction = (Direction)(-direction);
	//	scissorsActivity = SCISSORS_RETURN;
	//}
}

void CutmanScissors::setDy(int dy)
{
	this->dy = dy;
}

CutmanScissors::CutmanScissors()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_CUTMAN_SCISSORS];
	width = sprite->anims[0].frames[0].right - sprite->anims[0].frames[0].left;
	height = sprite->anims[0].frames[0].bottom - sprite->anims[0].frames[0].top;
	collisionType = CT_BULLET;
	scissorsActivity = SCISSORS_ATTACK;
	alive = false;
	direction = (Direction)(-1);
}


CutmanScissors::~CutmanScissors()
{
}
