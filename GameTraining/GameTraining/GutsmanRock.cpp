#include "GutsmanRock.h"
#include "GutsmanBrokenRock.h"
#include "Gutsman.h"

#define PI 3.14

double getBrokenRockDy(double dx, double alpha, double dx0, double dy0)
{
	double beta, gamma;

	beta = atan(abs(dy0 / dx0));

	gamma = alpha - beta;

	return tan(gamma) * dx;
}

GutsmanRock * GutsmanRock::instance = 0;

GutsmanRock * GutsmanRock::getInstance()
{
	if (instance == 0)
		instance = new GutsmanRock();
	return instance;
}

void GutsmanRock::update()
{
	rockBreakingDelay.update();
	if (!alive)
	{
		return;
	}

	if (onBreaking)
	{
		rockBreakingDelay.start();
		updateRockBreaking();
		return;
	}

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
			// TODO lam da vo~
			onBreaking = true;
			break;
		case GMR_THROW_FINISH:
			if (rockBreakingDelay.isTerminated())
			{
				for (size_t i = 0; i < GutsmanBrokenRock::rocks->Count; i++)
				{
					GutsmanBrokenRock::rocks->at(i)->deleteRock();
					i--;
				}
			}
			//alive = false;
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
	if (!alive || onBreaking)
		return;
	
	Enemy::render();
}

void GutsmanRock::updateRockBreaking()
{
	//
	//GutsmanBrokenRock* rock = new GutsmanBrokenRock();
	//rock->x = GutsmanRock::instance->getXCenter();
	//rock->y = GutsmanRock::instance->getYCenter();
	//rock->dx = 3 * Gutsman::instance->direction; // TODO
	//rock->dy = getBrokenRockDy(rock->dx, 30, dx, dy);
	//rock->setAction(action);

	//dx = 0;
	//dy = 0;

	onBreaking = false;
	gmrThrowActivity = GMR_THROW_FINISH;
		
}

void GutsmanRock::onCollision(FBox * other, int nx, int ny)
{
	if ((other->collisionType == CT_GROUND || other == Rockman::getInstance()) && gmrThrowActivity == GMR_THROW_NORMAL)
	{
		gmrThrowActivity = GMR_THROW_BREAKING;

		alive = false;

		float dxshort = 4 * Gutsman::instance->direction; // TODO
		float dxlong = 4.5 * Gutsman::instance->direction; // TODO

		GutsmanBrokenRock* rock = new GutsmanBrokenRock();
		rock->x = GutsmanRock::instance->getXCenter();
		rock->y = GutsmanRock::instance->getYCenter();
		rock->dx = dxlong;
		rock->dy = getBrokenRockDy(rock->dx, 20 * 2 * PI / 360, dx, dy);
		rock->setAction(action);

		rock = new GutsmanBrokenRock();
		rock->x = GutsmanRock::instance->getXCenter();
		rock->y = GutsmanRock::instance->getYCenter();
		rock->dx = dxshort;
		rock->dy = getBrokenRockDy(rock->dx, 10 * 2 * PI / 360, dx, dy);
		rock->setAction(action);

		rock = new GutsmanBrokenRock();
		rock->x = GutsmanRock::instance->getXCenter();
		rock->y = GutsmanRock::instance->getYCenter();
		rock->dx = dxlong;
		rock->dy = getBrokenRockDy(rock->dx, -10 * 2 * PI / 360, dx, dy);
		rock->setAction(action);

		rock = new GutsmanBrokenRock();
		rock->x = GutsmanRock::instance->getXCenter();
		rock->y = GutsmanRock::instance->getYCenter();
		rock->dx = dxshort;
		rock->dy = getBrokenRockDy(rock->dx, -20 * 2 * PI / 360, dx, dy);
		rock->setAction(action);

	}

	Enemy::onCollision(other, nx, ny);
	
}

GutsmanRock::GutsmanRock()
{
	sprite = SpriteManager::getInstance()->sprites[SPR_GUTSMAN_ROCK];
	width = sprite->getWidth(0, 0);
	height = sprite->getHeight(0, 0);
	onBreaking = false;
	alive = true;
	rockBreakingDelay.init(2000);
}


GutsmanRock::~GutsmanRock()
{
}
