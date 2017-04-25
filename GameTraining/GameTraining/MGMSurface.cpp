#include "MGMSurface.h"




void MGMSurface::error()
{
	MessageBox(0, "Không th? kh?i t?o surface", "Thông báo", MB_ICONERROR);
	PostQuitMessage(0);
}

MGMSurface::MGMSurface(const char* fileName)
{
	init(fileName);
}

void MGMSurface::init(const char* fileName)
{
	HRESULT hr;
	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFile(fileName, &info);
	int width = info.Width;
	int height = info.Height;
	hr = MGMDirectXTool::getInstance()->GetDevice()->CreateOffscreenPlainSurface(width,
		height,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&surface,
		0);
	if (FAILED(hr))
		error();

	D3DXLoadSurfaceFromFile(surface, 0, 0, fileName, 0, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), 0);
}


void MGMSurface::render(RECT* r,int x,int y,int w,int h)
{
	RECT rectPos ;
	rectPos.left=x;
	rectPos.top=y;

	rectPos.right=x+w;
	rectPos.bottom=y+h;
	MGMDirectXTool::getInstance()->GetDevice()->StretchRect(surface, 
															r, 
															MGMDirectXTool::getInstance()->GetBackBuffer(),
															&rectPos, 
															D3DTEXF_NONE);
}

void MGMSurface::release()
{
	if (surface)
	{
		surface->Release();
		surface = 0;
	}
}

MGMSurface::~MGMSurface()
{
	release();
}

