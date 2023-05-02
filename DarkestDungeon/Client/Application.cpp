#include "Application.h"
#include "SceneManager.h"
#include "Time.h"
#include "Input.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "SoundManager.h"

// handle��dc�� ������ �־���ϴϱ� handle,dc �ʱ�ȭ
Application::Application()
	: mHwnd(NULL)
	, mHdc(NULL)
{
}

Application::~Application()
{
	//SceneManager::Release();
}

void Application::Initialize(HWND hWnd)
{
	// handle�� ���ؼ� dc�� ������ �� ����
	mHwnd = hWnd;
	// getDC : ���� handle�� ����ִ� dc�� ������
	mHdc = GetDC(hWnd);

	// �ػ󵵸� ����س���
	mWidth = 1600;
	mHeight = 900;

	//��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�⸦ ������ش�.
	// RECT : �簢�� Ŭ����
	RECT rect = { 0, 0, mWidth , mHeight };
	// AdjustWindowRect : �۾�ǥ������ ���� ������ũ�⸦ �������ִ� �Լ��̴�.
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	// ������ ũ�� ����� ��� ����
	// cx : ���α���
	// cy : ���α���
	SetWindowPos(mHwnd
		, nullptr, 100, 50
		, rect.right - rect.left
		, rect.bottom - rect.top
		, 0);
	// �ٽ� ȭ�鿡 �׷��ش�.
	ShowWindow(hWnd, true);

	// BackBuffer : ��ȭ�� �� �� �� �߰� �Ѵٰ� �����ϸ�ȴ�.
	// ����� �ʱ�ȭ
	mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
	// ����� �޸� DC �ʱ�ȭ
	mBackHDC = CreateCompatibleDC(mHdc);
	// ����۰� mBackHDC�� ����� �ž�
	HBITMAP defaultBitmap
		= (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
	DeleteObject(defaultBitmap);

	Time::Initialize();
	Input::Initialize();
	SoundManager::Initialize();
	SceneManager::Initialize();
	// ī�޶� �߰�
	Camera::Initialize();
	
	// �޴��ٸ� ���ֱ� ����
	SetMenuBar(false);
}

void Application::Run()
{
	Update();
	Render();
	SceneManager::Destroy();
}

void Application::Update()
{
	Time::Update();
	Input::Update();
	Camera::Update();

	SceneManager::Update();
	CollisionManager::Update();
	
}
// ȭ���� �׷��� 
void Application::Render()
{
	// clear
	clear();
	// clear : �����ָ� �ȴ�.
	// ���� hdc�� 0���� 1602 902 ũ�⸸ŭ �����ָ� �ȴ�.
	// -1�� �� ������ ��Ȯ�� 0,0�̱⶧���� ������ ���ϳ��� ���̱� ������ 
	// �װ� ���ֱ� ���ؼ� -1,-1�� ������Ѵ�.
	//Rectangle(mBackHDC, -1, -1, 1602, 902);

	// ���� DC���ٰ� �׸��°� �ƴ϶� ����ۿ��ٰ� �׸��� ���̴�.
	// ����� �� ���� ����ۿ� �ִ� ���� ��������Ѵ�.
	Time::Render(mBackHDC);
	Input::Render(mBackHDC);
	SceneManager::Render(mBackHDC);
	
	// ����ۿ� �ִ� �׸��� �������ۿ� �׷�����Ѵ�.
	// BitBlt : DC�� �ִ� ���� �ٸ� DC�� �ִ� ���� �״�� �������ش�.
	BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
}

void Application::SetMenuBar(bool power)
{
	SetMenu(mHwnd, mMenubar);

	RECT rect = { 0, 0, mWidth , mHeight };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, power);

	// ������ ũ�� ����� ��� ����
	SetWindowPos(mHwnd
		, nullptr, 0, 0
		, rect.right - rect.left
		, rect.bottom - rect.top
		, 0);
	ShowWindow(mHwnd, true);
}

void Application::clear()
{
	// �Ͼ������ �ٲٰ� �ʹٸ� RGB ���� �ٲٸ� �ȴ�.
	HBRUSH grayBrush = CreateSolidBrush(RGB(121, 121, 121));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, grayBrush);
	Rectangle(mBackHDC, -1, -1, 1602, 902);
	SelectObject(mBackHDC, oldBrush);
	DeleteObject(grayBrush);
}
