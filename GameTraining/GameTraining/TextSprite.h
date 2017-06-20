#pragma once
#include "Sprite.h"
class TextSprite :
	public Sprite
{
public:
	static TextSprite* instance;

	static TextSprite* getInstance();
	void render(int x, int y, char* text);

	/* CONSTRUCTOR & DESTRUCTOR */	
	TextSprite();
	~TextSprite();

};

