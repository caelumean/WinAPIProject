#pragma once
#include "CommonInclude.h"

class Time
{
public:
	static void Initialize();
	static void Update();
	static void Render(HDC hdc);

	// 델타 타임 가져오는 함수 
	__forceinline static double DeltaTime() { return mDeltaTime; }

	private:
		static double mDeltaTime;
		static double mSecond;
		// LARGE_INTEGER 16바이트 정수
		// cpu 진동수
		static LARGE_INTEGER mCpuFrequency;
		// 컴퓨터 막 켰을 때 진동수
		static LARGE_INTEGER mPrevFrequency;
		// 현재 진동수
		static LARGE_INTEGER mCurFrequency;

};

