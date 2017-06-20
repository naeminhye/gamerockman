#include<Windows.h>
#include"Form.h"
#include"DirectXTool.h"
#include"MGMTexture.h"
#include"MGMSurface.h"
#include"MapScene.h"
#include"KEY.h"
#include"Scene.h"
#include"SelectMapScene.h"
#include"IntroScene.h"
#include<time.h>
#include<stdlib.h>

int randomFrom(int numBegin, int numEnd)
{
	return rand() % (numEnd - numBegin + 1) + numBegin;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(0));
	Form::getInstance()->initHandleWindows(hInstance, nCmdShow);
	DWORD timeSleep = 1000.0/FPS;

	CKeyboard::Create(hInstance,Form::getInstance()->getHandleWindow());
	Scene::changeScene(new IntroScene());
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));


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
		Scene::curScene->update();

		DirectXTool::getInstance()->BeginGraphics();//bat dau ve len backbuffer
		Scene::curScene->render();
		DirectXTool::getInstance()->EndGraphics();// ket thuc ve len backbuffer
		DirectXTool::getInstance()->PresentBackBuffer();// ve backbuffer len man hinh
		Sleep(timeSleep);
	}


	return nCmdShow;
}
