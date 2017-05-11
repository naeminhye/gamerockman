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
	sprites = new Sprite*[SPR_COUNT];
	
	/********************* rockman *********************/
	sprites[SPR_ROCKMAN] = new Sprite();
	sprites[SPR_ROCKMAN]->ReadFromFile("Data\\Sprite\\Rockman\\rockman.txt", "Data\\Sprite\\Rockman\\image.png");

	/*sprites[SPR_ENEMY_DEATH] = new Sprite();
	sprites[SPR_ENEMY_DEATH]->img = sprites[SPR_ROCKMAN]->img;
	sprites[SPR_ENEMY_DEATH]->readInfo("Data\\Sprite\\Enemies\\death.txt");*/

	/********************* enemies *********************/
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

	sprites[SPR_EYE] = new Sprite();
	sprites[SPR_EYE]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_EYE]->readInfo("Data\\Sprite\\Enemies\\BigEye\\bigeye.txt");

	sprites[SPR_BOMBER] = new Sprite();
	sprites[SPR_BOMBER]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_BOMBER]->readInfo("Data\\Sprite\\Enemies\\ScrewBomber\\screwbomber.txt");

	sprites[SPR_SHELL] = new Sprite();
	sprites[SPR_SHELL]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_SHELL]->readInfo("Data\\Sprite\\Enemies\\FlyingShell\\flyingshell.txt");

	sprites[SPR_CUTTER_BULLET] = new Sprite();
	sprites[SPR_CUTTER_BULLET]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_CUTTER_BULLET]->readInfo("Data\\Sprite\\Enemies\\SuperCutter\\supercutter.txt");

	sprites[SPR_BEAK_BULLET] = new Sprite();
	sprites[SPR_BEAK_BULLET]->img = sprites[SPR_OCTOPUS]->img;
	sprites[SPR_BEAK_BULLET]->readInfo("Data\\Sprite\\Enemies\\Beak\\beakbullet.txt");

	sprites[SPR_BULLET] = new Sprite();
	sprites[SPR_BULLET]->ReadFromFile("Data\\Sprite\\Rockman\\bullet.txt", "Data\\Sprite\\Rockman\\weapon.png");


	/********************* bosses *********************/ 
	sprites[SPR_CUTMAN] = new Sprite();
	sprites[SPR_CUTMAN]->ReadFromFile("Data\\Sprite\\Enemies\\Cutman\\cutman.txt", "Data\\Sprite\\Enemies\\Cutman\\Cutman.png");

	sprites[SPR_CUTMAN_SCISSORS] = new Sprite();
	sprites[SPR_CUTMAN_SCISSORS]->img = sprites[SPR_CUTMAN]->img;
	sprites[SPR_CUTMAN_SCISSORS]->readInfo("Data\\Sprite\\Enemies\\Cutman\\cutmanscissors.txt");

	/********************* others *********************/
	sprites[SPR_DOOR] = new Sprite();
	sprites[SPR_DOOR]->ReadFromFile("Data\\Sprite\\Door\\door.txt", "Data\\Sprite\\Door\\Door.png");
}




SpriteManager::~SpriteManager()
{
}
