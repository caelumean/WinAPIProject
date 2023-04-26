#pragma once
#include "Engine.h"

class Application
{
public:
	Application();
	~Application();

	//���� �ʱ�ȭ
	void Initialize(HWND hWnd);
	// ���� ����
	void Run();
	// ���� ������ 2���� �ɰ� ���̴�
	// ���� �����ϴ� �κ�
	void Update();
	// �׷��ִ� �κ�
	void Render();

	// �޴��� �Լ� �߰�
	void SetMenuBar(bool power);

	HWND GetHwnd() { return mHwnd; }
	HDC GetHdc() { return mHdc; }
	UINT GetWidth() { return mWidth; }
	UINT GetHeight() { return mHeight; }
private:
	void clear();
private:
	// Application�� �׻� ��� �־���ϴ� ���� �ִ� handle, dc
	HWND mHwnd;
	HDC mHdc;
	HMENU mMenubar;

	//�����
	// HBITMAP : BMP�� �����ϴ� Ȯ���ڰ� HBITMAP�̴�.
	HBITMAP mBackBuffer;
	// ����ۿ� �����ؼ� �׸��� �׸��� ���� 
	// �޸𸮸� ����Ű�� �ִ� ������ �ϳ� �� ������ش�.
	HDC mBackHDC;

	UINT mWidth;
	UINT mHeight;

	Vector2 mPos;
};

