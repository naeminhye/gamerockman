#pragma once
#include"Keyboard.h"
class KEY
{
public:
	bool	isLeftDown,
			isRightDown,
			isJumpDown,
			isPreviousJumpDown,
			isJumpPress,
			isUpDown,
			isDownDown,
			isMoveDown,
			isAttackDown,
			isPreviousAttackDown,
			isAttackPress;

	static KEY* instance;
	static KEY* getInstance();

	void update();
	
	KEY();
	~KEY();
};

