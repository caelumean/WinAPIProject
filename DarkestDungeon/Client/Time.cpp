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
	// CPU ���� ������ ��������
	QueryPerformanceFrequency(&mCpuFrequency);

	// ���α׷��� ó�� �����Ҷ� ������
	QueryPerformanceCounter(&mPrevFrequency);
}

void Time::Update()
{
	QueryPerformanceCounter(&mCurFrequency);

	// QuadPart : ��ȣ�ִ� 64��Ʈ ������ ���Ѵ�.
	// ���� ������ - ��ǻ�� ������ ������
	double differnceFrequency = mCurFrequency.QuadPart - mPrevFrequency.QuadPart;

	// differnceFrequency���� cpu���� ������ ������ �����ָ� �ȴ�.
	mDeltaTime = differnceFrequency / mCpuFrequency.QuadPart;

	// ���� ������ ����  ��ǻ�� ������ �������� �ٽ� �ʱ�ȭ ������Ѵ�.
	mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
}

void Time::Render(HDC hdc)
{
	mSecond += mDeltaTime;

	if (mSecond > 1.0f)
	{
		// application�� handle�� �����´�.
		HWND hWnd = application.GetHwnd();
		Vector2 MousePos = Input::GetMousePos();
		wchar_t szFloat[50] = {};

		float FPS = 1.0f / (float)mDeltaTime;
		// UINT : unsigned int ����ü
		swprintf_s(szFloat, 50, L"FPS : %d, x : %d, y : %d", (UINT)FPS, (UINT)MousePos.x, (UINT)MousePos.y);

		//int iLen = wcsnlen_s(szFloat, 50);
		// ������ â ���� ǥ������ �ؽ�Ʈ�� �����Ѵ�.
		SetWindowText(hWnd, szFloat);

		// mSecond �ʱ�ȭ
		mSecond = 0.0f;
	}
}
