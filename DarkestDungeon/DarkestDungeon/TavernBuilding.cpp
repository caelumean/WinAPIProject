#include "TavernBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

TavernBuilding::TavernBuilding()
{
}

TavernBuilding::~TavernBuilding()
{
}

void TavernBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"TavernBuilding", L"..\\Resources\\Town\\building\\town_tavern_1.bmp");
	GameObject::Initialize();
}

void TavernBuilding::Update()
{
	GameObject::Update();
}

void TavernBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 260, pos.y + 410, 300, 300
		, mImage->GetHdc(), 0, 0, 824, 814, RGB(255, 0, 255));
}
void TavernBuilding::Release()
{
	GameObject::Release();
}
