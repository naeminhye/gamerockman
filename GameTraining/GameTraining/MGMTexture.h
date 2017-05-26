#pragma once


#include"MGMDirectXTool.h"
#include"MGMPoint.h"

enum Direction
{
	Left = -1,
	Right = 1
};



class MGMTexture
{

private:
public:
	
	LPDIRECT3DTEXTURE9 m_image;
	int Width, Height;
	MGMPoint anchorPoint;
	Direction direction;

	MGMTexture(const char* filepath,D3DCOLOR transColor);
	////tao texture
	// filepath: duong dan file hinh anh
	// transColor: mau can trong suot
	MGMTexture(){}
	void Init(const char* filepath,D3DCOLOR transColor);

	////ham ve
	// x,y
	// r vung muon ve
	
	void RenderTexture(int x,int y,RECT *r);
	~MGMTexture();
};
