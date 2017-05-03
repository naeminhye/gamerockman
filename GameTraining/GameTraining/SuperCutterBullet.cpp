#include "SuperCutterBullet.h"

List<SuperCutterBullet*>* SuperCutterBullet::bullets = new List<SuperCutterBullet*>();

void SuperCutterBullet::update()
{
	MovableObject::update();
}

void SuperCutterBullet::deleteBullet()
{
	bullets->_Remove(this);
	delete this;
}

SuperCutterBullet::SuperCutterBullet()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_CUTTER_BULLET];
	width = sprite->anims[0].frames[0].right - sprite->anims[0].frames[0].left;
	height = sprite->anims[0].frames[0].bottom - sprite->anims[0].frames[0].top;
	bullets->_Add(this);
	collisionType = CT_BULLET;
}


SuperCutterBullet::~SuperCutterBullet()
{
}
