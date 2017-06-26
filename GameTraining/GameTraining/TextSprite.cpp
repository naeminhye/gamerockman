#include "TextSprite.h"



TextSprite * TextSprite::instance = 0;

TextSprite * TextSprite::getInstance()
{
	if (instance == 0)
		instance = new TextSprite();
	return instance;
}

void TextSprite::render(int x, int y, char * text)
{
	int space = 2; //TODO luu constant
	int n = strlen(text);
	for (int i = 0; i < n; i++)
	{
		int frameIndex = text[i] - 'A';
		Sprite::render(x, y, 0, frameIndex);
		x = x + anims[0].frames[frameIndex].right - anims[0].frames[frameIndex].left + space;
	}
}

TextSprite::TextSprite()
{
	ReadFromFile("Data\\Sprite\\Text\\textsprite.txt", "Data\\Sprite\\Text\\StageSelect.png");
}


TextSprite::~TextSprite()
{
}
