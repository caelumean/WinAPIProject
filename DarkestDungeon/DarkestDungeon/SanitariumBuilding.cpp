#include "SanitariumBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

SanitariumBuilding::SanitariumBuilding()
{
}

SanitariumBuilding::~SanitariumBuilding()
{
}

void SanitariumBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"SanitariumBuilding", L"..\\Resources\\Town\\building\\town_sanitarium_1.bmp");
	GameObject::Initialize();
}

void SanitariumBuilding::Update()
{
	GameObject::Update();
}

void SanitariumBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 430, pos.y + 150, 300, 500
		, mImage->GetHdc(), 0, 0, 764, 963, RGB(255, 0, 255));
}

void SanitariumBuilding::Release()
{
	GameObject::Release();
}
