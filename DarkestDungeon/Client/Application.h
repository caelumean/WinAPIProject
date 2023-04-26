#pragma once
#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	//게임 초기화
	void Initialize(HWND hWnd);
	// 게임 실행
	void Run();
	// 게임 실행을 2개로 쪼갤 것이다
	// 로직 실행하는 부분
	void Update();
	// 그려주는 부분
	void Render();

	// 메뉴바 함수 추가
	void SetMenuBar(bool power);

	HWND GetHwnd() { return mHwnd; }
	HDC GetHdc() { return mHdc; }
	UINT GetWidth() { return mWidth; }
	UINT GetHeight() { return mHeight; }
private:
	void clear();
private:
	// Application이 항상 들고 있어야하는 것이 있다 handle, dc
	HWND mHwnd;
	HDC mHdc;
	HMENU mMenubar;

	//백버퍼
	// HBITMAP : BMP를 저장하는 확장자가 HBITMAP이다.
	HBITMAP mBackBuffer;
	// 백버퍼에 접근해서 그림을 그리기 위한 
	// 메모리를 가리키고 있는 도구를 하나 더 만들어준다.
	HDC mBackHDC;

	UINT mWidth;
	UINT mHeight;

	Vector2 mPos;
};

