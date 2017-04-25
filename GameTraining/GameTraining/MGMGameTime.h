#pragma once
#include<Windows.h>
class MGMGameTime
{
public:
	DWORD startTime;
	DWORD tickPerFrame;
	DWORD deltaTime;

	MGMGameTime(void);
	~MGMGameTime(void);

	MGMGameTime(DWORD tickPerFrame);
	virtual bool atTime();
	virtual void start();
};

