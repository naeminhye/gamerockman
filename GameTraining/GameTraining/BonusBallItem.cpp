#include "BonusBallItem.h"



void BonusBallItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
	// TODO: Tang diem cho Rockman :)
}

BonusBallItem::BonusBallItem()
{
	frameIndex = BONUS_BALL;
}


BonusBallItem::~BonusBallItem()
{
}
