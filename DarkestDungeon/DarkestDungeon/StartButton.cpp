#include "StartButton.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

StartButton::StartButton()
{
}

StartButton::~StartButton()
{
}

void StartButton::Initialize()
{
	mImage = Resources::Load<Image>(L"StartButton", L"..\\Resources\\Title\\start_button.bmp");
	GameObject::Initialize();
}

void StartButton::Update()
{
	GameObject::Update();
}

void StartButton::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	
	TransparentBlt(hdc, pos.x + 650, pos.y + 800, 300, 70
		, mImage->GetHdc(), 0, 0, 372, 92, RGB(255, 0, 255));
}

void StartButton::Release()
{
	GameObject::Release();
}
