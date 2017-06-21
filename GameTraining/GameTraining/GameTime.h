#pragma once
#include<Windows.h>
class GameTime
{
public:
	DWORD startTime;
	DWORD tickPerFrame;
	DWORD deltaTime;

	/* CONSTRUCTOR & DESTRUCTOR */
	GameTime(void);
	~GameTime(void);


	GameTime(DWORD tickPerFrame);
	virtual bool atTime();
	virtual void start();
};

