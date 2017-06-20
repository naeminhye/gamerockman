#include "CutmanScissors.h"
#include"Cutman.h"

CutmanScissors * CutmanScissors::instance = 0;

CutmanScissors * CutmanScissors::getInstance()
{
	if (instance == 0)
		instance = new CutmanScissors();
	return instance;
}

void CutmanScissors::update()
{
	int delta = 10; // TODO luu constant
	BaseObject::update();
	switch (scissorsActivity)
	{
	case SCISSORS_ATTACK:
		if ((x < Stage::curStage->left() + delta && dx < 0) ||
			(x > Stage::curStage->right() - delta && dx > 0))
		{
			dx = -dx;
			scissorsActivity = SCISSORS_RETURN;
		}
		break;
	case SCISSORS_RETURN:
		if (Collision::AABBCheck(this, cutman))
		{
			alive = false;
			Cutman* cutman1 = ((Cutman*)cutman);
			cutman1->setType(CM_NON_ATTACKING);
			return;
		}
		if (x - cutman->x != 0)
		{
			dy = dx * (y - cutman->y) / (x - cutman->x);
		}
		break;
	default:
		break;
	}
}

CutmanScissors::CutmanScissors()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_CUTMAN_SCISSORS];
	width = sprite->anims[0].frames[0].right - sprite->anims[0].frames[0].left;
	height = sprite->anims[0].frames[0].bottom - sprite->anims[0].frames[0].top;
	collisionType = CT_BULLET;
	scissorsActivity = SCISSORS_ATTACK;
	alive = false;
}


CutmanScissors::~CutmanScissors()
{
}
