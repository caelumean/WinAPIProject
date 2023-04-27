#pragma once
#include "Engine.h"

// Ű ����
enum class eKeyCode
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,

	UP, DOWN, LEFT, RIGHT, SPACE,
	LBUTTON, RBUTTON,
	END,
};

enum class eKeyState
{
	Down,
	Pressed,
	Up,
	None,
};
class Input
{
public:
	struct Key
	{
		// � Ű����
		eKeyCode key;
		// Ű ���°� ��� 
		eKeyState state;
		// ���ȴ��� �ȴ��ȴ���
		bool bPressed;
	};

	static void Initialize();
	static void Update();
	static void Render(HDC hdc);

	inline static eKeyState GetKeyState(eKeyCode keyCode)
	{
		return mKeys[(UINT)keyCode].state;
	}
	//GetKey()		Ű�� ������ �ð���ŭ true�� ��ȯ
	//GetKeyDown()	Ű�� ������ ��, �� �ѹ� true�� ��ȯ
	//GetKeyUp()	Ű�� ������ ���� ��, �� �ѹ� true�� ��ȯ

	static __forceinline bool GetKey(eKeyCode keyCode)
	{
		return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::Pressed;
	}

	static __forceinline bool GetKeyDown(eKeyCode keyCode)
	{
		return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::Down;
	}

	static __forceinline bool GetKeyUp(eKeyCode keyCode)
	{
		return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::Up;
	}

	// ���콺
	static __forceinline Vector2 GetMousePos() { return mMousePos; }
private:
	// Ű�� ���� �������� ���� ����� Ű��ŭ �� ��� �־���Ѵ�.
	static std::vector<Key> mKeys;
	static Vector2 mMousePos;
};
