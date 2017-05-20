#include "OneUpItem.h"



void OneUpItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
}

OneUpItem::OneUpItem()
{
	frameIndex = ONE_UP;
}


OneUpItem::~OneUpItem()
{
}
