#include "BonusBallItem.h"
#include "Rockman.h"


void BonusBallItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
	GameSound::getInstance()->play(SOUND_BONUSBALL, false); 
	// TODO: Tang diem cho Rockman :)
}

BonusBallItem::BonusBallItem()
{
	frameIndex = BONUS_BALL;
}


BonusBallItem::~BonusBallItem()
{
}
