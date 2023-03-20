#include "BlacksmithBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

BlacksmithBuilding::BlacksmithBuilding()
{
}

BlacksmithBuilding::~BlacksmithBuilding()
{
	
}

void BlacksmithBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"BlacksmithBuilding", L"..\\Resources\\Town\\building\\town_blacksmith_1.bmp");
	GameObject::Initialize();
}

void BlacksmithBuilding::Update()
{
	GameObject::Update();
}

void BlacksmithBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 1100, pos.y + 450, 280, 300
		, mImage->GetHdc(), 0, 0, 719, 795, RGB(255, 0, 255));
}

void BlacksmithBuilding::Release()
{
	GameObject::Release();
}
