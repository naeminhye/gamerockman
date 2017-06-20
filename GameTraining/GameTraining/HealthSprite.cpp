#include "HealthSprite.h"

HealthSprite * HealthSprite::instance = 0;
HealthSprite * HealthSprite::getInstance()
{
	if (instance == 0)
		instance = new HealthSprite();
	return instance;
}

void HealthSprite::render(int left, int bottom, int healthCount, int maxHealth)
{
	int x = left;
	int y = bottom - maxHealth*height;
	int xRender, yRender;
	xRender = x;
	yRender = y;
	int healthLost = maxHealth - healthCount;

	for (int i = 0; i < maxHealth; i++)
	{
		yRender = y + i*height;
		if (i >= healthLost)
		{
			img->RenderTexture(xRender, yRender, 0);
		}
		else
		{
			DirectXTool::getInstance()->GetSprite()->Draw(img->m_image,
				0,
				0,
				&D3DXVECTOR3(xRender, yRender, 0),
				D3DCOLOR_XRGB(0, 0, 0));
		}
	}

}

HealthSprite::HealthSprite()
{
	Sprite::ReadFromFile("Data\\Sprite\\Health\\health.txt", "Data\\Sprite\\Health\\health.png");
	height = img->Height;
}


HealthSprite::~HealthSprite()
{
}
