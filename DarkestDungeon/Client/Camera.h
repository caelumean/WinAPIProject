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

	// pos�� �־��ָ� ī�޶� ��ǥ��� ��ȯ
	static Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }

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

