#include "OneUpItem.h"
#include "Rockman.h"


void OneUpItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
	Rockman::getInstance()->setHealth(Rockman::getInstance()->maxHealth);
	Rockman::getInstance()->setLife(Rockman::getInstance()->life + 1);
}

OneUpItem::OneUpItem()
{
	frameIndex = ONE_UP;
}


OneUpItem::~OneUpItem()
{
}
