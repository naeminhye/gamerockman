#pragma once
#include "BaseObject.h"
#include"DelayTime.h"
#include"SuperCutterBullet.h"
enum SUPERCUTTER_ACTIVITY {
	SUPERCUTTER_WAITING,
	SUPERCUTTER_SHOOTING
};

class SuperCutter :
	public BaseObject
{
public:
	SUPERCUTTER_ACTIVITY cutterActivity;
	DelayTime cutterDelay;
	void update();
	SuperCutter();
	~SuperCutter();

};

