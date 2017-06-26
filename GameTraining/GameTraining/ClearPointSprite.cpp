#include "ClearPointSprite.h"

ClearPointSprite * ClearPointSprite::instance = 0;

ClearPointSprite * ClearPointSprite::getInstance()
{
	if (instance == 0)
	{
		instance = new ClearPointSprite();
	}
	return instance;
}

void ClearPointSprite::render(int x, int y, int clearPoint)
{
	int maxchar = 6;
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

ClearPointSprite::ClearPointSprite()
{
	ReadFromFile("Data\\Sprite\\Text\\numbersprite.txt", "Data\\Sprite\\Text\\StageSelect.png");
}


ClearPointSprite::~ClearPointSprite()
{
}
