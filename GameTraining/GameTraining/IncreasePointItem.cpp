#include "IncreasePointItem.h"



void IncreasePointItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
	// TODO: Tang diem cho Rockman :)
}

IncreasePointItem::IncreasePointItem()
{
	frameIndex = INCREASE_POINT;
}


IncreasePointItem::~IncreasePointItem()
{
}
