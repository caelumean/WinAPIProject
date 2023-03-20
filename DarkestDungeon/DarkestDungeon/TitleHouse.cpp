#include "TitleHouse.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

TitleHouse::TitleHouse()
{
}

TitleHouse::~TitleHouse()
{
}

void TitleHouse::Initialize()
{
	mImage = Resources::Load<Image>(L"TitleHouse", L"..\\Resources\\Title\\title_house.bmp");
	GameObject::Initialize();
}

void TitleHouse::Update()
{
	GameObject::Update();
}

void TitleHouse::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	
	TransparentBlt(hdc, pos.x, pos.y+450, 1600, 500
		, mImage->GetHdc(), 0, 0, 1920, 674, RGB(255, 0, 255));
}

void TitleHouse::Release()
{
	GameObject::Release();
}
