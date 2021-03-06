#pragma once
#include"Keyboard.h"
class KEY
{
public:
	bool	isLeftDown, 
			isLeftPress,
			isPreviousLeftDown,
			isRightDown,
			isRightPress,
			isPreviousRightDown,
			isJumpDown,
			isPreviousJumpDown,
			isJumpPress,
			isUpDown,
			isUpPress,
			isPreviousUpDown,
			isDownDown,
			isDownPress,
			isPreviousDownDown,
			isMoveDown,
			isAttackDown,
			isPreviousAttackDown,
			isAttackPress, 
			isEnter,
			isEnterPress,
			isPreviousEnter,
			isQDown,
			isWDown;

	static KEY* instance;
	static KEY* getInstance();

	void update();

	/* CONSTRUCTOR & DESTRUCTOR */
	KEY();
	~KEY();

};

