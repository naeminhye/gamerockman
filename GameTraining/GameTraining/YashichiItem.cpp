#include "YashichiItem.h"



void YashichiItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
}

YashichiItem::YashichiItem()
{
	frameIndex = YASHICHI;
}


YashichiItem::~YashichiItem()
{
}
