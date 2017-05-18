#include "PicketBullet.h"

List<PicketBullet*>* PicketBullet::bullets = new List<PicketBullet*>();


void PicketBullet::deleteBullet()
{
	bullets->_Remove(this);
	delete this;
}

void PicketBullet::update()
{
	MovableObject::update();
}

PicketBullet::PicketBullet()
{
	bullets->_Add(this);
	sprite = SpriteManager::getInstance()->sprites[SPR_PICKET_BULLET];
	width = sprite->getWidth(0, 0);
	height = sprite->getHeight(0, 0);
	pauseAnimation = false;
	action = 0;
}


PicketBullet::~PicketBullet()
{
}
