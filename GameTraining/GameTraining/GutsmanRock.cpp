#include "GutsmanRock.h"

GutsmanRock * GutsmanRock::instance = 0;

GutsmanRock * GutsmanRock::getInstance()
{
	if (instance == 0)
		instance = new GutsmanRock();
	return instance;
}

void GutsmanRock::update()
{
	if (!alive)
		return;

	switch (gmrActivity)
	{
	case GMR_FALLING:
		Enemy::update();
		break;
	case GMR_THROWING:

		switch (gmrThrowActivity)
		{
		case GMR_THROW_NORMAL:
			break;
		case GMR_THROW_BREAKING:
			break;
		default:
			break;
		}


		break;
	default:
		break;
	}

	

	
}

void GutsmanRock::render()
{
	if (!alive)
		return;
	Enemy::render();
}

GutsmanRock::GutsmanRock()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_GUTSMAN_ROCK];
	width = sprite->getWidth(0, 0);
	height = sprite->getHeight(0, 0);
	alive = false;
}


GutsmanRock::~GutsmanRock()
{
}
