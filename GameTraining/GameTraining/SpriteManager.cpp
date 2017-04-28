#include "SpriteManager.h"



SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
		instance = new SpriteManager();
	return instance;
}

SpriteManager::SpriteManager()
{
	//add
	sprites = new Sprite*[SPR_COUNT];

	sprites[SPR_ROCKMAN] = new Sprite();
	sprites[SPR_ROCKMAN]->ReadFromFile("Data\\Sprite\\Rockman\\rockman.txt", "Data\\Sprite\\Rockman\\image.png");

	sprites[SPR_OCTOPUS] = new Sprite();
	sprites[SPR_OCTOPUS]->ReadFromFile("Data\\Sprite\\Enemies\\OctopusBattery\\octopusbattery.txt", "Data\\Sprite\\Enemies\\Enemies.png");

	sprites[SPR_BLADER] = new Sprite();
	sprites[SPR_BLADER]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_BLADER]->readInfo("Data\\Sprite\\Enemies\\Blader\\blader.txt");

	sprites[SPR_BEAK] = new Sprite();
	sprites[SPR_BEAK]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_BEAK]->readInfo("Data\\Sprite\\Enemies\\Beak\\beak.txt");

	sprites[SPR_FLEA] = new Sprite();
	sprites[SPR_FLEA]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_FLEA]->readInfo("Data\\Sprite\\Enemies\\Flea\\flea.txt");

	sprites[SPR_SUPERCUTTERBULLET] = new Sprite();
	sprites[SPR_SUPERCUTTERBULLET]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_SUPERCUTTERBULLET]->readInfo("Data\\Sprite\\Enemies\\SuperCutter\\supercutter.txt");

	sprites[SPR_BEAK_BULLET] = new Sprite();
	sprites[SPR_BEAK_BULLET]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_BEAK_BULLET]->readInfo("Data\\Sprite\\Enemies\\Beak\\beakbullet.txt");

	sprites[SPR_BULLET] = new Sprite();
	sprites[SPR_BULLET]->ReadFromFile("Data\\Sprite\\Rockman\\bullet.txt", "Data\\Sprite\\Rockman\\bullet.png");

}




SpriteManager::~SpriteManager()
{
}
