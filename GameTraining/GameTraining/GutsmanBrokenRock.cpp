#include "GutsmanBrokenRock.h"

List<GutsmanBrokenRock*>* GutsmanBrokenRock::rocks = new List<GutsmanBrokenRock*>();

void GutsmanBrokenRock::update()
{
	BaseObject::update();
}

void GutsmanBrokenRock::render()
{
	if (!alive)
		return;
	Enemy::render();
}

void GutsmanBrokenRock::deleteRock()
{
	rocks->_Remove(this);
	delete this;
}

void GutsmanBrokenRock::updateLocation()
{
	x += dx;
	y += dy;
}

void GutsmanBrokenRock::onCollision(FBox * other, int nx, int ny)
{

}

GutsmanBrokenRock::GutsmanBrokenRock()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_GUTSMAN_BROKEN_ROCK];
	width = sprite->getWidth(0, 0);
	height = sprite->getHeight(0, 0);
	rocks->_Add(this);
	attackDamage = GM_ROCK_ATTACK_DAMAGE;
}


GutsmanBrokenRock::~GutsmanBrokenRock()
{
}
