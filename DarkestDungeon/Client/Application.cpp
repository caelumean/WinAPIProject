#include "Application.h"
#include "SceneManager.h"
#include "Time.h"
#include "Input.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "SoundManager.h"

// handle과dc를 가지고 있어야하니까 handle,dc 초기화
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
	// handle를 통해서 dc를 가져올 수 있음
	mHwnd = hWnd;
	// getDC : 너의 handle에 들어있는 dc를 가져와
	mHdc = GetDC(hWnd);

	// 해상도를 기록해놓고
	mWidth = 1600;
	mHeight = 900;

	//비트맵 해상도를 설정하기 위한 실제 윈도우 크기를 계산해준다.
	// RECT : 사각형 클래스
	RECT rect = { 0, 0, mWidth , mHeight };
	// AdjustWindowRect : 작업표시줄을 빼고 윈도우크기를 조정해주는 함수이다.
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	// 윈도우 크기 변경및 출력 설정
	// cx : 가로길이
	// cy : 세로길이
	SetWindowPos(mHwnd
		, nullptr, 100, 50
		, rect.right - rect.left
		, rect.bottom - rect.top
		, 0);
	// 다시 화면에 그려준다.
	ShowWindow(hWnd, true);

	// BackBuffer : 도화지 한 장 더 추가 한다고 생각하면된다.
	// 백버퍼 초기화
	mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
	// 백버퍼 메모리 DC 초기화
	mBackHDC = CreateCompatibleDC(mHdc);
	// 백버퍼가 mBackHDC를 사용할 거야
	HBITMAP defaultBitmap
		= (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
	DeleteObject(defaultBitmap);

	Time::Initialize();
	Input::Initialize();
	SoundManager::Initialize();
	SceneManager::Initialize();
	// 카메라 추가
	Camera::Initialize();
	
	// 메뉴바를 없애기 위해
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
// 화면을 그려줌 
void Application::Render()
{
	// clear
	clear();
	// clear : 지워주면 된다.
	// 나의 hdc의 0부터 1602 902 크기만큼 지워주면 된다.
	// -1을 한 이유는 정확히 0,0이기때문에 맨위에 선하나가 보이기 때문에 
	// 그걸 없애기 위해서 -1,-1로 해줘야한다.
	//Rectangle(mBackHDC, -1, -1, 1602, 902);

	// 이제 DC에다가 그리는게 아니라 백버퍼에다가 그리는 것이다.
	// 지우는 것 또한 백버퍼에 있는 것을 지워줘야한다.
	Time::Render(mBackHDC);
	Input::Render(mBackHDC);
	SceneManager::Render(mBackHDC);
	
	// 백버퍼에 있는 그림을 원본버퍼에 그려줘야한다.
	// BitBlt : DC에 있는 것을 다른 DC에 있는 것을 그대로 복사해준다.
	BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
}

void Application::SetMenuBar(bool power)
{
	SetMenu(mHwnd, mMenubar);

	RECT rect = { 0, 0, mWidth , mHeight };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, power);

	// 윈도우 크기 변경및 출력 설정
	SetWindowPos(mHwnd
		, nullptr, 0, 0
		, rect.right - rect.left
		, rect.bottom - rect.top
		, 0);
	ShowWindow(mHwnd, true);
}

void Application::clear()
{
	// 하얀색으로 바꾸고 싶다면 RGB 값을 바꾸면 된다.
	HBRUSH grayBrush = CreateSolidBrush(RGB(121, 121, 121));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, grayBrush);
	Rectangle(mBackHDC, -1, -1, 1602, 902);
	SelectObject(mBackHDC, oldBrush);
	DeleteObject(grayBrush);
}
