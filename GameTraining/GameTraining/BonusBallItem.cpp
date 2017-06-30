#include "BonusBallItem.h"
#include "Rockman.h"


//void BonusBallItem::onIntersect(FBox * other)
//{
//	Item::onIntersect(other);
//	GameSound::getInstance()->play(SOUND_BONUSBALL); 
//	// TODO: Tang diem cho Rockman :)
//}

void BonusBallItem::rockmanBonus()
{
	GameSound::getInstance()->play(SOUND_BONUSBALL);
	Rockman::getInstance()->bonusPoint += BONUS_BALL_POINTS;
	// TODO: Tang diem cho Rockman :)
}

BonusBallItem::BonusBallItem()
{
	frameIndex = BONUS_BALL;
}


BonusBallItem::~BonusBallItem()
{
}
