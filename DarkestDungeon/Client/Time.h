#pragma once
#include "CommonInclude.h"

class Time
{
public:
	static void Initialize();
	static void Update();
	static void Render(HDC hdc);

	// ��Ÿ Ÿ�� �������� �Լ� 
	__forceinline static double DeltaTime() { return mDeltaTime; }

	private:
		static double mDeltaTime;
		static double mSecond;
		// LARGE_INTEGER 16����Ʈ ����
		// cpu ������
		static LARGE_INTEGER mCpuFrequency;
		// ��ǻ�� �� ���� �� ������
		static LARGE_INTEGER mPrevFrequency;
		// ���� ������
		static LARGE_INTEGER mCurFrequency;

};

