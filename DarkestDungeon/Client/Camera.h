#pragma once
#include "Engine.h"

class GameObject;
class Camera
{
public:
	// ī�޶� ����Ʈ
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
	// ī�޶�����Ʈ�� �ҷ��� Render���� ������ �ؾ��ϴϱ�
	static void Render(HDC hdc);
	static void Clear();

	static void SetTarget(GameObject* target) {mTarget = target;}

	static Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }
	static Vector2 GetDistance() { return mDistance; }

	static Vector2 GetLookPosition() { return mLookPosition; }
	static float GetAlphaTime() { return mAlphaTime; }
	static void SetLookPosition(Vector2 pos) { mLookPosition = pos; }

private:

	// ȭ�� �ػ�
	static Vector2 mResolution;
	// �� ī�޶� �Ĵٺ��� �ִ� ��ġ
	static Vector2 mLookPosition;
	// �Ÿ�
	static Vector2 mDistance;
	// ���� �Ĵٺ� ���� ������Ʈ
	static GameObject* mTarget;

	// ���� ī�޶� ����Ʈ �ִ��� �˾ƾ��ϴϱ�
	static eCameraEffectType mType;
	// ȭ�� ���� ��� �̹��� �־���ϴϱ�
	static class Image* mCutton;
	static float mCuttonAlpha;
	// Ŀư�� ���İ�
	static float mAlphaTime;
	// ������ �ð�
	static float mEndTime;

};

