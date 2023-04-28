#include "Time.h"
#include "Input.h"
#include "Application.h"

extern Application application;

double Time::mDeltaTime = 0.0l;
double Time::mSecond = 0.0f;
LARGE_INTEGER Time::mCpuFrequency = {};
LARGE_INTEGER Time::mPrevFrequency = {};
LARGE_INTEGER Time::mCurFrequency = {};

void Time::Initialize()
{
	// CPU 고유 진동수 가져오기
	QueryPerformanceFrequency(&mCpuFrequency);

	// 프로그램이 처음 시작할때 진동수
	QueryPerformanceCounter(&mPrevFrequency);
}

void Time::Update()
{
	QueryPerformanceCounter(&mCurFrequency);

	// QuadPart : 부호있는 64비트 정수를 뜻한다.
	// 현재 진동수 - 컴퓨터 켰을때 진동수
	double differnceFrequency = mCurFrequency.QuadPart - mPrevFrequency.QuadPart;

	// differnceFrequency값을 cpu고유 진동수 값으로 나눠주면 된다.
	mDeltaTime = differnceFrequency / mCpuFrequency.QuadPart;

	// 현재 진동수 값을  컴퓨터 켰을때 진동수로 다시 초기화 해줘야한다.
	mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
}

void Time::Render(HDC hdc)
{
	mSecond += mDeltaTime;

	if (mSecond > 1.0f)
	{
		// application의 handle을 가져온다.
		HWND hWnd = application.GetHwnd();
		Vector2 MousePos = Input::GetMousePos();
		wchar_t szFloat[50] = {};

		float FPS = 1.0f / (float)mDeltaTime;
		// UINT : unsigned int 구조체
		swprintf_s(szFloat, 50, L"FPS : %d, x : %d, y : %d", (UINT)FPS, (UINT)MousePos.x, (UINT)MousePos.y);

		//int iLen = wcsnlen_s(szFloat, 50);
		// 지정된 창 제모 표시줄의 텍스트를 변경한다.
		SetWindowText(hWnd, szFloat);

		// mSecond 초기화
		mSecond = 0.0f;
	}
}
