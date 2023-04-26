#pragma once
#include "Engine.h"

class GameObject;
class Camera
{
public:
	// 카메라 이팩트
	enum class eCameraEffectType
	{
		None,
		FadeIn,
		FadeOut,
		//Shake,
		End,
	};

	static void Initialize();
	static void Update();
	// 카메라이팩트를 할려면 Render에도 개입을 해야하니까
	static void Render(HDC hdc);
	static void Clear();

	static void SetTarget(GameObject* target) {mTarget = target;}

	// pos를 넣어주면 카메라 좌표계로 전환
	static Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }

private:

	// 화면 해상도
	static Vector2 mResolution;
	// 이 카메라가 쳐다보고 있는 위치
	static Vector2 mLookPosition;
	// 거리
	static Vector2 mDistance;
	// 내가 쳐다볼 게임 오브젝트
	static GameObject* mTarget;

	// 무슨 카메라 임팩트 있는지 알아야하니까
	static eCameraEffectType mType;
	// 화면 덮을 까만색 이미지 있어야하니까
	static class Image* mCutton;
	static float mCuttonAlpha;
	// 커튼의 알파값
	static float mAlphaTime;
	// 끝나는 시간
	static float mEndTime;
};

