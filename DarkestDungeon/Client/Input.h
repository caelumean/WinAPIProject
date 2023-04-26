#pragma once
#include "Engine.h"

// 키 정보
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
		// 어떤 키인지
		eKeyCode key;
		// 키 상태가 어떤지 
		eKeyState state;
		// 눌렸는지 안눌렸는지
		bool bPressed;
	};

	static void Initialize();
	static void Update();
	static void Render(HDC hdc);

	inline static eKeyState GetKeyState(eKeyCode keyCode)
	{
		return mKeys[(UINT)keyCode].state;
	}
	//GetKey()		키를 누르는 시간만큼 true를 반환
	//GetKeyDown()	키를 눌렀을 때, 딱 한번 true를 반환
	//GetKeyUp()	키를 누르다 땠을 때, 딱 한번 true를 반환

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

	// 마우스
	static __forceinline Vector2 GetMousePos() { return mMousePos; }
private:
	// 키에 대한 정보들을 내가 사용할 키만큼 다 들고 있어야한다.
	static std::vector<Key> mKeys;
	static Vector2 mMousePos;
};

