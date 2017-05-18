#include "Death.h"

List<Death*>* Death::deaths = new List<Death*>();

void Death::release()
{
	deaths->_Remove(this);
	delete this;
}

void Death::onLastFrameAnimation()
{
	release();
}

Death::Death()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_ENEMY_DEATH];
	deaths->_Add(this);
}


Death::~Death()
{
}
