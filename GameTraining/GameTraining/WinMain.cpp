#include<Windows.h>
#include"MGMForm.h"
#include"MGMDirectXTool.h"
#include"MGMTexture.h"
#include"MGMSurface.h"
#include"MGMGame.h"
#include"KEY.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MGMForm::getInstance()->initHandleWindows(hInstance, nCmdShow);
	DWORD timeSleep = 1000.0/FPS;

	CKeyboard::Create(hInstance,MGMForm::getInstance()->getHandleWindow());

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	MGMGame::getInstance()->init();

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		CKeyboard::getInstance()->PollKeyboard();
		CKeyboard::getInstance()->UpdateKeyboard();
		KEY::getInstance()->update();

		MGMGame::getInstance()->update();
		MGMDirectXTool::getInstance()->BeginGraphics();//bat dau ve len backbuffer
		MGMGame::getInstance()->render();
		MGMDirectXTool::getInstance()->EndGraphics();// ket thuc ve len backbuffer
		MGMDirectXTool::getInstance()->PresentBackBuffer();// ve backbuffer len man hinh
		Sleep(timeSleep);
	}


	return nCmdShow;
}
