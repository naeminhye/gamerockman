#include "GameTime.h"


GameTime::GameTime(void)
{
}

void GameTime::start()
{
	startTime = GetTickCount();
}

GameTime::GameTime(DWORD tickPerFrame)
{
	this->tickPerFrame = tickPerFrame;
}


bool GameTime::atTime()
{

	DWORD now = GetTickCount();
	deltaTime = now - startTime;

	if(deltaTime>=tickPerFrame)
	{
		startTime = GetTickCount();
		return true;
	}

	return false;
}

GameTime::~GameTime(void)
{
}


