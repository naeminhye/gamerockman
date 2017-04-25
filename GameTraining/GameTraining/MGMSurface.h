#pragma once

#include"MGMDirectXTool.h"

class MGMSurface
{
protected:

	LPDIRECT3DSURFACE9 surface;

	void error();
	
public:
	MGMSurface(){}
	MGMSurface(const char* fileName);
	void init(const char* fileName);
	void render(RECT* r,int x,int y,int w,int h);
	void release();
	~MGMSurface();
};