#include "MagnetBeamItem.h"



void MagnetBeamItem::onIntersect(FBox * other)
{
	Item::onIntersect(other);
}

MagnetBeamItem::MagnetBeamItem()
{
	frameIndex = MAGNET_BEAM;
}


MagnetBeamItem::~MagnetBeamItem()
{
}
