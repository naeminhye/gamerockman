#include "NumberSprite.h"

NumberSprite * NumberSprite::instance = 0;

NumberSprite * NumberSprite::getInstance()
{
	if (instance == 0)
	{
		instance = new NumberSprite();
	}
	return instance;
}

void NumberSprite::render(int x, int y, int num, int clearPoint)
{
	int maxchar = num;
	string numberString = std::to_string(clearPoint);
	int space = 1; //TODO luu constant
	int n = numberString.size();
	for (int i = 0; i < maxchar; i++)
	{
		if (i < maxchar - n )
		{
			Sprite::render(x, y, 0, 0);
			x = x + anims[0].frames[0].right - anims[0].frames[0].left + space;
			continue;
		}
		int frameIndex = numberString[i- maxchar + n] - '0';
		Sprite::render(x, y, 0, frameIndex);
		x = x + anims[0].frames[frameIndex].right - anims[0].frames[frameIndex].left + space;
	}
}

NumberSprite::NumberSprite()
{
	ReadFromFile("Data\\Sprite\\Text\\numbersprite.txt", "Data\\Sprite\\Text\\StageSelect.png");
}


NumberSprite::~NumberSprite()
{
}
