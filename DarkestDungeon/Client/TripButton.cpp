#include "TripButton.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

TripButton::TripButton()
{
}

TripButton::~TripButton()
{
}

void TripButton::Initialize()
{
	mImage = Resources::Load<Image>(L"Trip_Button", L"..\\Resources\\Town\\trip_button.bmp");
	GameObject::Initialize();
}

void TripButton::Update()
{
	GameObject::Update();
}

void TripButton::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 680, pos.y + 803, 300, 45
		, mImage->GetHdc(), 0, 0, 312, 52, RGB(255, 0, 255));
}

void TripButton::Release()
{
	GameObject::Release();
}
