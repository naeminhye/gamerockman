#include "Item.h"

List<Item*>* Item::items = new List<Item*>();

void Item::release()
{
	items->_Remove(this);
	delete this;
}

void Item::onIntersect(FBox * other)
{
	release();
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
