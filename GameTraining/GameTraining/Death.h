#pragma once
#include "BaseObject.h"
#include "List.h"
class Death :
	public BaseObject
{
public:
	static List<Death*>* deaths;
	void release();
	void onLastFrameAnimation();
	Death();
	~Death();
};

