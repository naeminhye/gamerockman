#include "Item.h"
#include"Rockman.h"

List<Item*>* Item::items = new List<Item*>();

void Item::release()
{
	items->_Remove(this);
	delete this;
}

//void Item::onIntersect(FBox * other)
//{
//	/*if(other==Rockman::getInstance() || other->collisionType == CT_GROUND)
//		release();*/
//}

void Item::rockmanBonus()
{
}

Item::Item()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_ITEMS];

	action = 0;
	pauseAnimation = true;
	items->_Add(this);
	collisionType = CT_ITEM;
}

Item::~Item()
{
}
