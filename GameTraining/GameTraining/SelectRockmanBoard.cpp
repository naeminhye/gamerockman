#include "SelectRockmanBoard.h"



void SelectRockmanBoard::render()
{
	RECT r;
	SetRect(&r, 0, 0, 96, 155); // TODO
	img->RenderTexture(x, y, &r);
}

SelectRockmanBoard::SelectRockmanBoard()
{
	img = new MGMTexture();
	img->Init("Data\\Sprite\\Scene\\Board.png", D3DCOLOR_XRGB(0, 255, 0));
}


SelectRockmanBoard::~SelectRockmanBoard()
{
}
