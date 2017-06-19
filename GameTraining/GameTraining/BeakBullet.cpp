#include "BeakBullet.h"

List<BeakBullet*>* BeakBullet::bullets = new List<BeakBullet*>();

bool BeakBullet::setHealthPoint(int healthPoint)
{
	return false;
}

void BeakBullet::update()
{
}

void BeakBullet::deleteBullet()
{
	bullets->_Remove(this);
	delete this;
}

void BeakBullet::updateLocation()
{
	x += dx;
	y += dy;
}

BeakBullet::BeakBullet()
{
 	sprite = SpriteManager::getInstance()->sprites[SPR_BEAK_BULLET];
	width = sprite->anims[0].frames[0].right - sprite->anims[0].frames[0].left;
	height = sprite->anims[0].frames[0].bottom - sprite->anims[0].frames[0].top;
	bullets->_Add(this);
	collisionType = CT_BULLET;
	direction = Left;
}


BeakBullet::~BeakBullet()
{
}
