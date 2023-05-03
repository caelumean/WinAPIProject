#pragma once
#include "Engine.h"

class GameObject;
class Camera
{
public:

	static void Initialize();
	static void Update();
	static void Clear();

	static void SetTarget(GameObject* target) { mTarget = target; }
	static Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }
	static Vector2 InitializePos(Vector2 pos) { return pos + mDistance; }
	static void SetLookPosition(Vector2 pos) { mLookPosition = pos; }

	static void SetMinX(float f) { MinX = f; }
	static void SetMaxX(float f) { MaxX = f; }
	static void SetMinY(float f) { MinY = f; }
	static void SetMaxY(float f) { MaxY = f; }

private:

	// ȭ�� �ػ�
	static Vector2 mResolution;
	// �� ī�޶� �Ĵٺ��� �ִ� ��ġ
	static Vector2 mLookPosition;
	// �Ÿ�
	static Vector2 mDistance;
	// ���� �Ĵٺ� ���� ������Ʈ
	static GameObject* mTarget;

	static float MinX;
	static float MaxX;
	static float MinY;
	static float MaxY;

};

