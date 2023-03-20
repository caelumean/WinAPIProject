#include "AbbeyBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

AbbeyBuilding::AbbeyBuilding()
{
}

AbbeyBuilding::~AbbeyBuilding()
{
}

void AbbeyBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"AbbeyBuilding", L"..\\Resources\\Town\\building\\town_abbey_1.bmp");
	GameObject::Initialize();
}

void AbbeyBuilding::Update()
{
	GameObject::Update();
}

void AbbeyBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 620, pos.y + 200, 400, 400
		, mImage->GetHdc(), 0, 0, 800, 986, RGB(255, 0, 255));
}

void AbbeyBuilding::Release()
{
	GameObject::Release();
}
