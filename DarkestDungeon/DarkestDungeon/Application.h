#pragma once
#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	void Initialize(HWND hWnd);
	void Run();
	void Update();
	void Render();

	HWND GetHwnd() { return mHwnd; }
	HDC GetHdc() { return mHdc; }

private:
	void clear();

private:
	HWND mHwnd;
	HDC mHdc;

	//�����
	HBITMAP mBackBuffer;
	HDC mBackHDC;

	UINT mWidth;
	UINT mHeight;

	Vector2 mPos;
};


