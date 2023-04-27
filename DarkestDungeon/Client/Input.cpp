#include "Input.h"
#include "Application.h"

extern Application application;
// �ƽ�Ű�ڵ忡 ¦���缭 ��ġ���� ��
int ASCII[(UINT)eKeyCode::END] =
{
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M',

	VK_UP, VK_DOWN, VK_LEFT ,VK_RIGHT, VK_SPACE,

	VK_LBUTTON, VK_RBUTTON,
};

// Ű �ʱ�ȭ
// ���δϱ� �𸣱� ������ Input class�ȿ� �ִ� key�̴�.
std::vector<Input::Key> Input::mKeys;
Vector2 Input::mMousePos = Vector2::Zero;

void Input::Initialize()
{
	for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
	{
		Key keyInfo;
		keyInfo.key = (eKeyCode)i;
		keyInfo.state = eKeyState::None;
		keyInfo.bPressed = false;

		mKeys.push_back(keyInfo);
	}
}

void Input::Update()
{
	// â�� ������ ������ �ϴ� ������ �ֱ� ������ �Է��� ��������Ѵ�.
	// ������ â�� Ȱ��ȭ �Ǿ����� ���� �Է��� ��������ش�.
	if (GetFocus())
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// ���� �����ӿ��� �����־��� ���ݵ� ���� ����
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;

				mKeys[i].bPressed = true;
			}

			//���� �����ӿ� Ű�� ���������ʴ�.
			else
			{
				// ���� �����ӿ� ��Ű�� �����־���.
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;
				mKeys[i].bPressed = false;
			}
		}
		POINT mousePos = {};
		GetCursorPos(&mousePos);

		ScreenToClient(application.GetHwnd(), &mousePos);
		mMousePos.x = mousePos.x;
		mMousePos.y = mousePos.y;
	}

	else
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			if (eKeyState::Down == mKeys[i].state
				|| eKeyState::Pressed == mKeys[i].state)
			{
				mKeys[i].state = eKeyState::Up;
			}
			else if (eKeyState::Up == mKeys[i].state)
			{
				mKeys[i].state = eKeyState::None;
			}

			mKeys[i].bPressed = false;
		}
	}
}

void Input::Render(HDC hdc)
{
}