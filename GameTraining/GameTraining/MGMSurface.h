#pragma once

#include"DirectXTool.h"

class MGMSurface
{
protected:

	LPDIRECT3DSURFACE9 surface;

	void error();
	
public:

	/* CONSTRUCTOR & DESTRUCTOR */
	MGMSurface() {}
	MGMSurface(const char* fileName);
	~MGMSurface();

	void init(const char* fileName);
	void render(RECT* r, int x, int y, int w, int h);
	void release();
};